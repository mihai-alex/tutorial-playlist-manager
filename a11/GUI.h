#pragma once

#include <QtWidgets/QMainWindow>
#include <QPainter>
#include "ui_a11.h"
#include "controller.h"
#include <vector>
#include <fstream>
#include <exception>

class GUI : public QMainWindow
{
    Q_OBJECT

private:
    std::vector<Tutorial*> currentWatchlistElements;
    std::string lastDeleted;

public:
    GUI(Controller& ctrl, QWidget* parent = Q_NULLPTR);

private:
    Ui::a11Class ui{};
    Controller& ctrl;
    void populate();
    void add();
    void connect();
    void deleteByTitle();
    void updateByTitle();
    void alloc_html();
    void alloc_csv();
    void seeTutorials();
    void populateUser();
    void nextWatchlist();
    void addWatchlist();
    void deleteFromWatchlist();
    void likeTutorial();
    void ignoreTutorial();

    // lab activity
    void paintEvent(QPaintEvent* event);
};