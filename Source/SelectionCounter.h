class SelectionCounter{

public:
    SelectionCounter();
    ~SelectionCounter();
    static void increaseSelected();
    static void decreaseSelected();
    static void resetSelected();
    static bool twoSelected();

private:
    static int selectedStones;

};