#ifndef VIEW_H
#define VIEW_H

class View {
public:
    static void showMainMenu();
    static int askMainOption();

    static void showClientMenu();
    static int askClientOption();

    static void showManagerMainMenu();
    static int askManagerMainOption();

};

#endif // VIEW_H
