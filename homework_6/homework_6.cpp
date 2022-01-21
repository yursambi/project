#include <iostream> 
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>

void PrintHello()
{
    std::cout << "              Здравствуйте, Дмитрий!" << std::endl;
}

// Выделяем память под одномерный массив и инициализируем его значениями степеней двойки
// используем функции EntryArray(), CorrArray(), IncorrArray()

bool CorrArray(int *ptrArr, int size)  //вызывается в функциях EntryArray() и IncorrArray() в случае 
{                                      //введения корректного размера массива
    const int base = 2;
    ptrArr = new (std::nothrow) int[size];

    if (ptrArr != nullptr)
    {
        for (size_t i = 0; i < size; i++)
        {
            ptrArr[i] = int(pow(base, i)); //unsigned long long - степень двойки до 64, int - степень двойки до 31
            std::cout << " " << ptrArr[i] << " ";
        }
        std::cout << " - массив инициализирован значениями степеней двойки" << std::endl;  //от 0 до (size - 1)

        delete[] ptrArr;
        ptrArr = 0;  //nullptr в C++11
    }
    else
    {
        std::cout << " Ошибка! Не удается выделить память!";
    }

    return true;
}

bool IncorrArray(int *ptrArr, int size, const int maxSize)  //вызывается в функции EntryArray() в случае
{                                                           //введения некорректного размера массива
    std::cout << " Введите корректный размер массива:             size = ";
    std::cin >> size;
    std::cout << std::endl;

    if (size > 0 && size <= maxSize)
    {
        CorrArray(ptrArr, size);
    }
    else
    {
        std::cout << " Попробуйте ещё раз:                            size = ";
        std::cin >> size;
        std::cout << std::endl;
        if (size > 0 && size <= maxSize)
        {
            CorrArray(ptrArr, size);
        }
        else
        {
            std::cout << " Вы опять ввели некорректный размер массива!" << std::endl;
            std::cout << " Попробуйте в следующий раз." << std::endl;
        }
    }
    return true;
}

bool EntryArray()  //вызывается в функции main()
{
    std::cout << " Выделяем память под одномерный массив" << std::endl;
    std::cout << " и инициализируем его значениями степеней двойки" << std::endl;

    const int maxSize = 31;
    int *ptrArr = 0;
    int size;
    std::cout << " Задайте размер вашего массива от 1 до 31:      size = "; 
    std::cin >> size;
    std::cout << std::endl;

    if (size > 0 && size <= maxSize)
    {
        CorrArray(ptrArr, size);
    }
    else if (size <= 0 || size > maxSize)
    {
        IncorrArray(ptrArr, size, maxSize);
    }
    return true;
}

bool FourArray(const size_t m, const size_t n)
{
    std::cout << " Динамически выделяем матрицу 4х4 типа int" << std::endl;
    std::cout << " и инициализируем её псевдослучайными числами" << std::endl;
    std::cout << std::endl;
    const int MAX_RAND = 1000;
    srand(static_cast<unsigned int>(time(0))); // устанавливаем значение системных часов в качестве стартового числа
    int** ptrFour;
    ptrFour = new int* [m];
    for (size_t i = 0; i < m; i++)
    {
        ptrFour[i] = new int[n];
    }

    for (size_t i = 0; i < m; i++)
        for (size_t j = 0; j < n; j++)
            ptrFour[i][j] = rand() % MAX_RAND;

    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
            std::cout << " Four[" << i << "][" << j << "] = " << ptrFour[i][j] << " \t";
        std::cout << std::endl;
        std::cout << std::endl;
    }

    for (size_t i = 0; i < m; i++)
    {
        delete[] ptrFour[i];
    }
    delete[] ptrFour;
    ptrFour = 0;

    return true;
}

bool WriteFile()
{
    std::cout << " Создаём и заполняем два текстовых файла с помощью" << std::endl;
    std::cout << " массива char и выводим их содержимое на экран" << std::endl;
    std::cout << std::endl;
    const size_t size_a = 37;
    const size_t size_b = 39;

    char  symbol_a[size_a] = {'Y','o','u','_','c','a','n','_','p','l','a','y','_','a','n','y','_','c','h','a','r','a','c','t','e','r','_','y','o','u','_','w','a','n','t',',','_'};
    char  symbol_b[size_b] = {'a','s','_','l','o','n','g','_','a','s','_','t','h','a','t','_','c','h','a','r','a','c','t','e','r','_','i','s','_','a','_','m','o','n','s','t','e','r','.'};

    std::ofstream fout("mydata_a.txt");
    std::ofstream fout2("mydata_b.txt");

    for (char element : symbol_a)
    {
        fout << element << " ";  
    } 
    fout.close();

    for (char element : symbol_b)
    {
        fout2 << element << " ";
    }
    fout2.close();

    char  symbol_c[size_a] = {0};
    char  symbol_d[size_b] = {0};

    std::ifstream fin("mydata_a.txt");
    std::ifstream fin2("mydata_b.txt");

    if (fin.is_open()) 
    {        
       for (int i = 0; i < size_a; i++)
       {
           fin >> symbol_c[i]; 
           std::cout << symbol_c[i] << ""; 
       }
       fin.close(); 
    }
    else 
    {
        std::cout << "Ошибка. Не удается открыть файл."; 
    }
    std::cout << std::endl;
    std::cout << std::endl;
    if (fin2.is_open())
    {
       for (int j = 0; j < size_b; j++)
       {
           fin2 >> symbol_d[j];
           std::cout << symbol_d[j] << "";
       }
       fin2.close();
    }
    else
    {
        std::cout << "Ошибка. Не удается открыть файл.";
    }
    std::cin.get(); 
    
    return true;
} 

bool ReadFile()
{
    std::cout << " Создаём и читаем два текстовых файла с помощью std::string," << std::endl;
    std::cout << " а затем склеиваем их в третий файл и выводим содержимое на экран" << std::endl;
    std::cout << "\n";
    std::cout << " Введите название первого файла:    ";
    std::string mytxt1;
    std::getline(std::cin, mytxt1); 
    std::cout << " Введите название второго файла:    ";
    std::string mytxt2;
    std::getline(std::cin, mytxt2);
    std::cout << "\n";
    std::ofstream fout1(mytxt1);
    std::ofstream fout2(mytxt2);

    fout1 << " Atticus, let's get on with these proceedings, and let the record show" << std::endl;
    fout2 << " that the witness has not been sassed, her views to the contrary." << std::endl;

    std::ifstream fin1(mytxt1);
    std::ifstream fin2(mytxt2);

    while (fin1 && fin2)
    {
        std::string strInput;
        getline(fin1, strInput);
        std::cout << strInput;// << std::endl;
        std::cout << "\n";
        std::cout << "\n";
        getline(fin2, strInput);
        std::cout << strInput;// << std::endl;
    }
    fin1.close(); fin2.close();
    //std::cout << "\n";
    std::cout << " Введите название третьего файла:   ";
    std::string mytxt3;
    std::getline(std::cin, mytxt3);
    std::cout << "\n";
    std::ifstream fin_1(mytxt1);  
    std::ifstream fin_2(mytxt2);
    std::ofstream fout3(mytxt3);
    std::string str1, str2;
    while (!fin_1.eof() || !fin_2.eof())
    {
        if (std::getline(fin_1, str1))
            fout3 << str1;
        if (std::getline(fin_2, str2))
            fout3 << str2 << std::endl;
    }

    std::ifstream fin3(mytxt3);

    while (fin3)
    {
        std::string strInput;
        getline(fin3, strInput);
        std::cout << strInput << std::endl;
    }
    fin_1.close(); fin_2.close(); fin3.close();

   return true;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    //std::cout << std::endl;
    PrintHello();
    std::cout << "\n";
    EntryArray();
    std::cout << "\n";
    const size_t m = 4;
    const size_t n = 4;    
    FourArray(m, n);
    std::cout << "\n";
    WriteFile();
    std::cout << "\n";
    std::cout << "\n";
    ReadFile();
    std::cout << std::endl;

    return 0;
}

