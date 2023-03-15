
//#ifndef PROJEKT_SDIZO_NR_1_SZYMON_BORZDYNSKI_ELEMENTLISTY_H
//#define PROJEKT_SDIZO_NR_1_SZYMON_BORZDYNSKI_ELEMENTLISTY_H
class ElementListy {

public:
    ElementListy *nastepny;
    ElementListy *poprzedni;
    int wartosc;

    ElementListy(int, ElementListy *, ElementListy *);
};
//#endif //PROJEKT_SDIZO_NR_1_SZYMON_BORZDYNSKI_ELEMENTLISTY_H


