Разработать макрос UNIQ_ID, который будет формировать идентификатор, уникальный в пределах данного cpp-файла.
Например, следующий код должен компилироваться и работать:
```
int UNIQ_ID = 5;
string UNIQ_ID = "hello!";
```
В рамках данной задачи допускается, что код
```
int UNIQ_ID = 5; string UNIQ_ID = "hello"; // оба определения на одной строке
```
не будет компилироваться.