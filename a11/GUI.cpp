#include "GUI.h"

using namespace std;

GUI::GUI(Controller& _ctrl, QWidget* parent)
	: QMainWindow(parent), ctrl{ _ctrl }
{
	ui.setupUi(this);
	populate();
	connect();
	populateUser();
}

void GUI::populateUser()
{
	try {
		ctrl.readWatchlistFromFile();
		this->ui.userList->clear();
		vector<Tutorial*> input = ctrl.getAllTutorialsWatchList();
		for (auto& element : input)
			this->ui.userList->addItem(QString::fromStdString(element->toStr()));
	}
	catch (exception& ex) {

	}
}

void GUI::populate()
{
	try {
		ctrl.readTutorialsFromFile();
		this->ui.adminList->clear();
		vector<Tutorial*> input = ctrl.getAllTutorials();
		for (auto& element : input)
			this->ui.adminList->addItem(QString::fromStdString(element->toStr()));
	}
	catch (exception& ex) {

	}
}

void GUI::add()
{
	string new_title = "";
	string presenter = "";
	int minutes = 0;
	int seconds = 0;
	int likes = 0;
	string link = "";

	try {
		new_title = this->ui.newTitleEdit->text().toStdString();
		InputValidator::validateString(new_title);

		presenter = this->ui.presenterEdit->text().toStdString();
		InputValidator::validateString(presenter);

		minutes = std::stoi(this->ui.minutesEdit->text().toStdString());
		seconds = std::stoi(this->ui.secondsEdit->text().toStdString());
		likes = std::stoi(this->ui.likesEdit->text().toStdString());

		link = this->ui.linkEdit->text().toStdString();
		InputValidator::validateString(link);

		Tutorial* t = new Tutorial(new_title, presenter, Pair{ minutes, seconds }, likes, link);

		ctrl.addTutorialObject(*t);
		ctrl.writeTutorialsToFile();
		populate();
	}
	catch (exception& ex) {

	}
}

void GUI::deleteByTitle()
{
	string old_title = this->ui.originalEdit->text().toStdString();

	try {
		ctrl.deleteTutorial(old_title);
		lastDeleted = old_title;
		ctrl.writeTutorialsToFile();
		populate();
	}
	catch (exception& ex) {

	}

	try {
		ctrl.deleteTutorialWatchList(old_title);
		ctrl.writeWatchlistToFile();
		populateUser();
	}
	catch (exception& ex) {

	}
}

void GUI::updateByTitle()
{
	string old_title = "";
	string new_title = "";
	string presenter = "";
	int minutes = 0;
	int seconds = 0;
	int likes = 0;
	string link = "";

	try {
		old_title = this->ui.originalEdit->text().toStdString();
		InputValidator::validateString(old_title);

		new_title = this->ui.newTitleEdit->text().toStdString();
		InputValidator::validateString(new_title);

		presenter = this->ui.presenterEdit->text().toStdString();
		InputValidator::validateString(presenter);

		minutes = std::stoi(this->ui.minutesEdit->text().toStdString());
		seconds = std::stoi(this->ui.secondsEdit->text().toStdString());
		likes = std::stoi(this->ui.likesEdit->text().toStdString());

		link = this->ui.linkEdit->text().toStdString();
		InputValidator::validateString(link);

		ctrl.updateTutorial(old_title, new_title, presenter, minutes, seconds, likes, link);
		ctrl.writeTutorialsToFile();
		populate();
	}
	catch (exception& ex) {

	}

	try {
		ctrl.updateTutorialWatchlist(old_title, new_title, presenter, minutes, seconds, likes, link);
		ctrl.writeWatchlistToFile();
		populateUser();
	}
	catch (exception& ex) {

	}
}

void GUI::alloc_html()
{
	ctrl.allocWatchlistHTML();
	populateUser();
}

void GUI::alloc_csv()
{
	ctrl.allocWatchlistCSV();
	populateUser();
}

void GUI::seeTutorials()
{
	string presenterName = this->ui.presenterNameEdit->text().toStdString();
	if (presenterName == "") {
		currentWatchlistElements = ctrl.getAllTutorials();
	}
	else {
		currentWatchlistElements = ctrl.filterByPresenter(presenterName);
	}

	ui.userList->clear();
	if (currentWatchlistElements.size() > 0) {
		this->ui.userList->addItem(QString::fromStdString(currentWatchlistElements.back()->toStr()));
		ctrl.openFileExternal();
	}
}

void GUI::nextWatchlist() {
	ui.userList->clear();
	if (currentWatchlistElements.size() > 0) {
		currentWatchlistElements.pop_back();
	}

	if (currentWatchlistElements.size() > 0) {
		this->ui.userList->addItem(QString::fromStdString(currentWatchlistElements.back()->toStr()));
		ctrl.openFileExternal();
	}
}

void GUI::addWatchlist() {
	ui.userList->clear();
	if (currentWatchlistElements.size() == 0) {
		return;
	}

	try {
		ctrl.addTutorialToWatchList(*currentWatchlistElements.back());
		currentWatchlistElements.pop_back();
		ctrl.writeWatchlistToFile();
		populateUser();
	}
	catch (exception& ex) {

	}

	if (currentWatchlistElements.size() > 0) {
		ui.userList->clear();
		this->ui.userList->addItem(QString::fromStdString(currentWatchlistElements.back()->toStr()));
		ctrl.openFileExternal();
	}
}

void GUI::deleteFromWatchlist() {

	string title = this->ui.deleteTutorialEdit->text().toStdString();

	try {
		ctrl.deleteTutorialWatchList(title);
		lastDeleted = title;
		ctrl.writeWatchlistToFile();
		populateUser();
	}
	catch (exception& ex) {
		nextWatchlist();

	}
}

void GUI::likeTutorial() {

	try {
		ctrl.likeTutorial(lastDeleted);
		lastDeleted = "";
		ctrl.writeTutorialsToFile();
		populate();
	}
	catch (exception& ex) {

	}
}

void GUI::ignoreTutorial() {
	lastDeleted = "";
}

void GUI::connect()
{
	QObject::connect(this->ui.addButton, &QPushButton::clicked, this, &GUI::add);
	QObject::connect(this->ui.deleteButton, &QPushButton::clicked, this, &GUI::deleteByTitle);
	QObject::connect(this->ui.updateButton, &QPushButton::clicked, this, &GUI::updateByTitle);
	QObject::connect(this->ui.HTML, &QPushButton::clicked, this, &GUI::alloc_html);
	QObject::connect(this->ui.CSV, &QPushButton::clicked, this, &GUI::alloc_csv);
	QObject::connect(this->ui.seeTutorialsButton, &QPushButton::clicked, this, &GUI::seeTutorials);
	QObject::connect(this->ui.nextButton, &QPushButton::clicked, this, &GUI::nextWatchlist);
	QObject::connect(this->ui.addTutorialButton, &QPushButton::clicked, this, &GUI::addWatchlist);
	QObject::connect(this->ui.deleteTutorialButton, &QPushButton::clicked, this, &GUI::deleteFromWatchlist);
	QObject::connect(this->ui.likeTutorialButton, &QPushButton::clicked, this, &GUI::likeTutorial);
	QObject::connect(this->ui.ignoreTutorialButton, &QPushButton::clicked, this, &GUI::ignoreTutorial);
}

// lab activity
void GUI::paintEvent(QPaintEvent* event) {
	QPainter painter(this);

	QLinearGradient linearGradient(QPointF(100, 100), QPointF(200, 200));
	linearGradient.setColorAt(0, Qt::black);
	linearGradient.setColorAt(1, Qt::white);
	QRect linearRect(0, 0, width(), height());
	painter.fillRect(linearRect, linearGradient);
}