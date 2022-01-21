#include <iostream>
#include <random>
#include <stdlib.h>
#include <chrono>

//=================================================================================

void PrintHello()
{
    std::cout << "             Здравствуйте, Дмитрий!" << std::endl << std::endl;
    std::cout << "         Представляем консольную игру" << std::endl << "             Крестики - Нолики" << std::endl;
    std::cout << "         Человек против компьютера" << std::endl;
    std::cout << "         Издатель DRACOTAIL GmbH" << std::endl << "         Все права защищены" << std::endl;
}

//=================================================================================

enum TCell: char {
    CROSS = 88,
    ZERO = 79,
    EMPTY = 32
};

enum TGameProgress {
    IN_PROGRESS,
    WON_HUMAN,
    WON_AI,
    DRAW 
};

struct TCoord {
    size_t x;
    size_t y;
};

struct TGameField {
    TCell** ppField{ nullptr };
    //const size_t size{5};  //  игровое поле 5x5
    int size{0};
    TCell human{CROSS};
    TCell ai{ZERO};
    size_t turn{0};  //  чётные - человек, нечётные - компьютер
    TGameProgress progress{IN_PROGRESS};
};

//=================================================================================


inline void clearScr()
{
    system("cls");
    //std::cout << "\x1B[2J\x1B[H";
}

int32_t __fastcall getRandomNum(int32_t min, int32_t max)
{
    const static auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    static std::mt19937_64 generator(seed);
    std::uniform_int_distribution<int32_t>dis(min, max);
    return dis(generator);
}

//=================================================================================

int __fastcall sizeGameField(TGameField & gf)
{
    while (true) 
    {
        std::cout << std::endl;
        std::cout << " Задайте размер игрового поля (size x size)" << std::endl;
        std::cout << " в диапазоне от трёх до пяти включительно:  size = ";
        std::cin >> gf.size;
        std::cout << std::endl;
        if (gf.size < 3 || gf.size > 5)
        {
            std::cin.clear(); 
            std::cin.ignore(32767, '\n'); 
            std::cout << " Некорректный ввод. Пожалуйста, попробуйте снова.\n";
        }
        else
        {
            std::cin.ignore(32767, '\n');
            return gf.size;
        }
    }
}


void __fastcall initGame(TGameField & gf)
{
    gf.ppField = new TCell * [gf.size];
    for (size_t i = 0; i < gf.size; i++)
    {
        gf.ppField[i] = new TCell[gf.size];
    }
    for (size_t x = 0; x < gf.size; x++)
    {
        for (size_t y = 0; y < gf.size; y++)
        {
            gf.ppField[x][y] = EMPTY;
        }
    }

    if (getRandomNum(0, 1000) > 500)
    {
        gf.human = CROSS;
        gf.ai = ZERO;
        gf.turn = 0;
    }
    else
    {
        gf.human = ZERO;
        gf.ai = CROSS;
        gf.turn = 1;
    }
}

void __fastcall deinitGame(TGameField & gf)
{
    for (size_t i = 0; i < gf.size; i++)
    {
        delete[] gf.ppField[i];
    }
    delete[] gf.ppField;
    gf.ppField = nullptr;
}

void __fastcall printGame(const TGameField & gf)
{
    std::cout << "  Консольная игра" << std::endl << "  Крестики - Нолики" << std::endl << "  Издатель DRACOTAIL GmbH" << std::endl;
    std::cout << std::endl;
    std::cout << "       " ;
    for (size_t y = 0; y < gf.size; y++)
        std::cout << y + 1 << "   ";
    std::cout << std::endl << std::endl;
    for (size_t x = 0; x < gf.size; x++)
    {
        std::cout << " " << x + 1 << "  " << " | ";
        for (size_t y = 0; y < gf.size; y++)
        {
            std::cout << gf.ppField[x][y] << " | ";
        }
        std::cout << std::endl << std::endl;
    }
    std::cout << std::endl << " Человек:    " << gf.human << std::endl << " Компьютер:  " << gf.ai << std::endl;

}

TGameProgress __fastcall getWon(const TGameField & gf)
{
    if (gf.size == 5)  //  игровое поле 5х5
    {
        //проверяем выигрыш в строках 
        for (size_t x = 0; x < gf.size; x++)
            if (gf.ppField[x][0] == gf.ppField[x][1] && gf.ppField[x][0] == gf.ppField[x][2] && gf.ppField[x][0] == gf.ppField[x][3] && gf.ppField[x][0] == gf.ppField[x][4])
            {
                if (gf.ppField[x][0] == gf.human)
                    return WON_HUMAN;

                if (gf.ppField[x][0] == gf.ai)
                    return WON_AI;
            }

        //проверяем выигрыш в столбцах 
        for (size_t y = 0; y < gf.size; y++)
            if (gf.ppField[0][y] == gf.ppField[1][y] && gf.ppField[0][y] == gf.ppField[2][y] && gf.ppField[0][y] == gf.ppField[3][y] && gf.ppField[0][y] == gf.ppField[4][y])
            {
                if (gf.ppField[0][y] == gf.human)
                    return WON_HUMAN;

                if (gf.ppField[0][y] == gf.ai)
                    return WON_AI;
            }

        //проверяем выигрыш в диагоналях
        if (gf.ppField[0][0] == gf.ppField[1][1] && gf.ppField[0][0] == gf.ppField[2][2] && gf.ppField[0][0] == gf.ppField[3][3] && gf.ppField[0][0] == gf.ppField[4][4])
        {
            if (gf.ppField[0][0] == gf.human)
                return WON_HUMAN;

            if (gf.ppField[0][0] == gf.ai)
                return WON_AI;
        }

        if (gf.ppField[4][0] == gf.ppField[3][1] && gf.ppField[4][0] == gf.ppField[2][2] && gf.ppField[4][0] == gf.ppField[1][3] && gf.ppField[4][0] == gf.ppField[0][4])
        {
            if (gf.ppField[4][0] == gf.human)
                return WON_HUMAN;

            if (gf.ppField[4][0] == gf.ai)
                return WON_AI;
        }
    }
    else if (gf.size == 4)  //  игровое поле 4х4
    {
        //проверяем выигрыш в строках 
        for (size_t x = 0; x < gf.size; x++)
            if (gf.ppField[x][0] == gf.ppField[x][1] && gf.ppField[x][0] == gf.ppField[x][2] && gf.ppField[x][0] == gf.ppField[x][3])
            {
                if (gf.ppField[x][0] == gf.human)
                    return WON_HUMAN;

                if (gf.ppField[x][0] == gf.ai)
                    return WON_AI;
            }

        //проверяем выигрыш в столбцах 
        for (size_t y = 0; y < gf.size; y++)
            if (gf.ppField[0][y] == gf.ppField[1][y] && gf.ppField[0][y] == gf.ppField[2][y] && gf.ppField[0][y] == gf.ppField[3][y])
            {
                if (gf.ppField[0][y] == gf.human)
                    return WON_HUMAN;

                if (gf.ppField[0][y] == gf.ai)
                    return WON_AI;
            }

        //проверяем выигрыш в диагоналях
        if (gf.ppField[0][0] == gf.ppField[1][1] && gf.ppField[0][0] == gf.ppField[2][2] && gf.ppField[0][0] == gf.ppField[3][3])
        {
            if (gf.ppField[0][0] == gf.human)
                return WON_HUMAN;

            if (gf.ppField[0][0] == gf.ai)
                return WON_AI;
        }

        if (gf.ppField[3][0] == gf.ppField[2][1] && gf.ppField[3][0] == gf.ppField[1][2] && gf.ppField[3][0] == gf.ppField[0][3])
        {
            if (gf.ppField[3][0] == gf.human)
                return WON_HUMAN;

            if (gf.ppField[3][0] == gf.ai)
                return WON_AI;
        }
    }
    else if (gf.size == 3)  //  игровое поле 3х3
    {
        //проверяем выигрыш в строках 
        for (size_t x = 0; x < gf.size; x++)
            if (gf.ppField[x][0] == gf.ppField[x][1] && gf.ppField[x][0] == gf.ppField[x][2])
            {
                if (gf.ppField[x][0] == gf.human)
                    return WON_HUMAN;

                if (gf.ppField[x][0] == gf.ai)
                    return WON_AI;
            }

        //проверяем выигрыш в столбцах 
        for (size_t y = 0; y < gf.size; y++)
            if (gf.ppField[0][y] == gf.ppField[1][y] && gf.ppField[0][y] == gf.ppField[2][y])
            {
                if (gf.ppField[0][y] == gf.human)
                    return WON_HUMAN;

                if (gf.ppField[0][y] == gf.ai)
                    return WON_AI;
            }

        //проверяем выигрыш в диагоналях
        if (gf.ppField[0][0] == gf.ppField[1][1] && gf.ppField[0][0] == gf.ppField[2][2])
        {
            if (gf.ppField[0][0] == gf.human)
                return WON_HUMAN;

            if (gf.ppField[0][0] == gf.ai)
                return WON_AI;
        }

        if (gf.ppField[2][0] == gf.ppField[1][1] && gf.ppField[2][0] == gf.ppField[0][2])
        {
            if (gf.ppField[2][0] == gf.human)
                return WON_HUMAN;

            if (gf.ppField[2][0] == gf.ai)
                return WON_AI;
        }
    }
     
    //проверяем ничью
    bool draw{true};
    for (size_t x = 0; x < gf.size; x++)
    {
        for (size_t y = 0; y < gf.size; y++)
        {
            if (gf.ppField[x][y] == EMPTY)
            {
                draw = false;
                break;
            }
        }
        if (!draw)
            break;
    }
    if (draw)
        return DRAW;

    return IN_PROGRESS;
}

TCoord __fastcall getHumanCoord(const TGameField & gf)
{
    TCoord c{};
    do
    {
        std::cout << std::endl;
        std::cout << " Введите координату клетки по горизонтали (от 1 до " << gf.size << ")" << ":   "; 
        std::cin >> c.y;
        std::cout << std::endl;
        std::cout << " Введите координату клетки по вертикали   (от 1 до " << gf.size << ")" << ":   ";  
        std::cin >> c.x;
        c.y--;
        c.x--;
    }
    while (c.x > (gf.size) - 1 || c.y > (gf.size) - 1 || gf.ppField[c.x][c.y] != EMPTY);

    return c;
}

TCoord __fastcall getAiCoord(TGameField & gf)
{
    //предвыигрышная ситуация
    for (size_t x = 0; x < gf.size; x++)
    {
        for (size_t y = 0; y < gf.size; y++)
        {
            if (gf.ppField[x][y] == EMPTY)
            {
                gf.ppField[x][y] == gf.ai;
                if (getWon(gf) == WON_AI)
                {
                    gf.ppField[x][y] == EMPTY;
                    return { x, y };
                }
                gf.ppField[x][y] == EMPTY;
            }
        }
    }

    //предпроигрышная ситуация
    for (size_t x = 0; x < gf.size; x++)
    {
        for (size_t y = 0; y < gf.size; y++)
        {
            if (gf.ppField[x][y] == EMPTY)
            {
                gf.ppField[x][y] == gf.human;
                if (getWon(gf) == WON_HUMAN)
                {
                    gf.ppField[x][y] == EMPTY;
                    return { x, y };
                }
                gf.ppField[x][y] == EMPTY;
            }
        }
    }

    if (gf.size == 5)  //  игровое поле 5х5
    {
        //ходы по приоритетам
        if (gf.ppField[1][1] == EMPTY)
        {
            return { 1, 1 };
        }

        TCoord buf[10];
        size_t num{ 0 };
        if (gf.ppField[0][0] == EMPTY)
        {
            buf[num] = { 0, 0 };
            num++;
        }
        if (gf.ppField[2][2] == EMPTY)
        {
            buf[num] = { 2, 2 };
            num++;
        }
        if (gf.ppField[2][0] == EMPTY)
        {
            buf[num] = { 2, 0 };
            num++;
        }
        if (gf.ppField[0][2] == EMPTY)
        {
            buf[num] = { 0, 2 };
            num++;
        }
        if (gf.ppField[3][0] == EMPTY)
        {
            buf[num] = { 3, 0 };
            num++;
        }
        if (gf.ppField[0][3] == EMPTY)
        {
            buf[num] = { 0, 3 };
            num++;
        }
        if (gf.ppField[3][3] == EMPTY)
        {
            buf[num] = { 3, 3 };
            num++;
        }
        if (gf.ppField[4][0] == EMPTY)
        {
            buf[num] = { 4, 0 };
            num++;
        }
        if (gf.ppField[0][4] == EMPTY)
        {
            buf[num] = { 0, 4 };
            num++;
        }
        if (gf.ppField[4][4] == EMPTY)
        {
            buf[num] = { 4, 4 };
            num++;
        }
        if (num > 0)
        {
            const size_t index = rand() % num;
            return buf[index];
        }

        //оставшиеся клетки
        num = 0;
        if (gf.ppField[0][1] == EMPTY)
        {
            buf[num] = { 0, 1 };
            num++;
        }
        if (gf.ppField[1][0] == EMPTY)
        {
            buf[num] = { 1, 0 };
            num++;
        }
        if (gf.ppField[1][2] == EMPTY)
        {
            buf[num] = { 1, 2 };
            num++;
        }
        if (gf.ppField[2][1] == EMPTY)
        {
            buf[num] = { 2, 1 };
            num++;
        }
        if (gf.ppField[1][3] == EMPTY)
        {
            buf[num] = { 1, 3 };
            num++;
        }
        if (gf.ppField[3][1] == EMPTY)
        {
            buf[num] = { 3, 1 };
            num++;
        }
        if (gf.ppField[2][3] == EMPTY)
        {
            buf[num] = { 2, 3 };
            num++;
        }
        if (gf.ppField[3][2] == EMPTY)
        {
            buf[num] = { 3, 2 };
            num++;
        }
        if (gf.ppField[1][4] == EMPTY)
        {
            buf[num] = { 1, 4 };
            num++;
        }
        if (gf.ppField[4][1] == EMPTY)
        {
            buf[num] = { 4, 1 };
            num++;
        }
        if (gf.ppField[2][4] == EMPTY)
        {
            buf[num] = { 2, 4 };
            num++;
        }
        if (gf.ppField[4][2] == EMPTY)
        {
            buf[num] = { 4, 2 };
            num++;
        }
        if (gf.ppField[3][4] == EMPTY)
        {
            buf[num] = { 3, 4 };
            num++;
        }
        if (gf.ppField[4][3] == EMPTY)
        {
            buf[num] = { 4, 3 };
            num++;
        }
        if (num > 0)
        {
            const size_t index = rand() % num;
            return buf[index];
        }
    }
    else if (gf.size == 4)  //  игровое поле 4х4
    {
        //ходы по приоритетам
        if (gf.ppField[1][1] == EMPTY)
        {
        return { 1, 1 };
        }

        TCoord buf[7];
        size_t num{ 0 };
        if (gf.ppField[0][0] == EMPTY)
        {
            buf[num] = { 0, 0 };
            num++;
        }
        if (gf.ppField[2][2] == EMPTY)
        {
            buf[num] = { 2, 2 };
            num++;
        }
        if (gf.ppField[2][0] == EMPTY)
        {
            buf[num] = { 2, 0 };
            num++;
        }
        if (gf.ppField[0][2] == EMPTY)
        {
            buf[num] = { 0, 2 };
            num++;
        }
        if (gf.ppField[3][0] == EMPTY)
        {
            buf[num] = { 3, 0 };
            num++;
        }
        if (gf.ppField[0][3] == EMPTY)
        {
            buf[num] = { 0, 3 };
            num++;
        }
        if (gf.ppField[3][3] == EMPTY)
        {
            buf[num] = { 3, 3 };
            num++;
        }
        if (num > 0)
        {
            const size_t index = rand() % num;
            return buf[index];
        }

        //оставшиеся клетки
        num = 0;
        if (gf.ppField[0][1] == EMPTY)
        {
            buf[num] = { 0, 1 };
            num++;
        }
        if (gf.ppField[1][0] == EMPTY)
        {
            buf[num] = { 1, 0 };
            num++;
        }
        if (gf.ppField[1][2] == EMPTY)
        {
            buf[num] = { 1, 2 };
            num++;
        }
        if (gf.ppField[2][1] == EMPTY)
        {
            buf[num] = { 2, 1 };
            num++;
        }
        if (gf.ppField[1][3] == EMPTY)
        {
            buf[num] = { 1, 3 };
            num++;
        }
        if (gf.ppField[3][1] == EMPTY)
        {
            buf[num] = { 3, 1 };
            num++;
        }
        if (gf.ppField[2][3] == EMPTY)
        {
            buf[num] = { 2, 3 };
            num++;
        }
        if (gf.ppField[3][2] == EMPTY)
        {
            buf[num] = { 3, 2 };
            num++;
        }
        if (num > 0)
        {
            const size_t index = rand() % num;
            return buf[index];
        }
    }
    else if (gf.size == 3)  //  игровое поле 3х3
    { 
        //ходы по приоритетам
        if (gf.ppField[1][1] == EMPTY)
        {
        return { 1, 1 };
        }

        TCoord buf[4];
        size_t num{ 0 };
        if (gf.ppField[0][0] == EMPTY)
        {
            buf[num] = { 0, 0 };
            num++;
        }
        if (gf.ppField[2][2] == EMPTY)
        {
            buf[num] = { 2, 2 };
            num++;
        }
        if (gf.ppField[2][0] == EMPTY)
        {
            buf[num] = { 2, 0 };
            num++;
        }
        if (gf.ppField[0][2] == EMPTY)
        {
            buf[num] = { 0, 2 };
            num++;
        }
        if (num > 0)
        {
            const size_t index = rand() % num;
            return buf[index];
        }

        //оставшиеся клетки
        num = 0;
        if (gf.ppField[0][1] == EMPTY)
        {
            buf[num] = { 0, 1 };
            num++;
        }
        if (gf.ppField[1][0] == EMPTY)
        {
            buf[num] = { 1, 0 };
            num++;
        }
        if (gf.ppField[1][2] == EMPTY)
        {
            buf[num] = { 1, 2 };
            num++;
        }
        if (gf.ppField[2][1] == EMPTY)
        {
            buf[num] = { 2, 1 };
            num++;
        }
        if (num > 0)
        {
            const size_t index = rand() % num;
            return buf[index];
        }
    }
}

inline void congratsWinner(const TGameField& gf)
{
    std::cout << std::endl;
    if (gf.progress == WON_HUMAN)
        std::cout << " Победил человек! :-)" << std::endl;
    else if (gf.progress == WON_AI)
        std::cout << " Победил Компьютер! :=/" << std::endl;
    else if (gf.progress == DRAW)
        std::cout << " Победила дружба! Ничья! :=)" << std::endl;
}     

//=================================================================================

int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << std::endl;
    PrintHello();
    std::cout << std::endl;

    TGameField gf;
    sizeGameField(gf);
    initGame(gf);
    clearScr();
    std::cout << std::endl;
    printGame(gf);

    do
    {
        if (gf.turn % 2 == 0)
        {
            //ходит человек
            TCoord c = getHumanCoord(gf);
            gf.ppField[c.x][c.y] = gf.human;
        }
        else
        {
            //ходит компьютер
            TCoord c = getAiCoord(gf);
            gf.ppField[c.x][c.y] = gf.ai;
        }

        clearScr();
        std::cout << std::endl;
        printGame(gf);
        gf.turn = gf.turn + 1;
        gf.progress = getWon(gf);

    }
    while (gf.progress == IN_PROGRESS);

    congratsWinner(gf);
    deinitGame(gf);

    std::cout << std::endl;
    return 0;
}

//=================================================================================
