# Отчёт по курсовой работе №6

---

## по курсу "Алгоритмы и структуры данных"


Студент группы М8О-108Б-23 Романов Вадим Михайлович

Работа выполнена

Преподаватель: каф.806 Севастьянов Виктор Сергеевич
1. Тема: Обработка последовательной файловой структуры на языке Си
2. Цель работы: разработать последовательную структуру данных для представления простейшей базы данных на файлах в СП Си, где находятся сведения о вступительных экзаменах абитуриентов: фамилия, инициалы, пол, номер школы, наличие медали, оценки в баллах и зачёт/незачёт по сочинению. Составить программу генерации внешнего нетекстового файла заданной структуры, содержащего представительный набор записей (15-20)
3. Задание: найти абитуриентов, имеющих заданную сумму баллов p
4. Идея, метод, алгоритм решения задачи:
- взять часть идей для выполнения задания из материалов к ЛР;
- перенести идею этих наработок в свою работу и значительно всё упростить;
- научиться работать с бинарными файлами методом проб и ошибок.
5. Сценарий выполнения работы:
- создать структуру данных Student для хранения всей информации об абитуриенте;
- организовать ввод данных с консоли в бинарный файл;
- обработать данные непосредственно в файле и подсчитать всех необходимых абитуриентов;
- не забыть подчистить за собой память.
6. Протокол:
В отдельном файле программы.

8. Выводы: я думаю, на 806 кафедре никто не в курсе, что для работы с такими БД уже существует вполне нормальная программа под названием Excel. Она тянет огромнейшие таблицы без каких-либо проблем и спартанский Си для работы с БД просто не нужен. К примеру, моё задание можно выполнить, используя элементарные фильтры.