# Отчёт по куровому проекту №8

---

## по курсу "Алгоритмы и структуры данных"


Студент группы М8О-108Б-23 Романов Вадим Михайлович

Работа выполнена

Преподаватель: каф.806 Севастьянов Виктор Сергеевич
1. Тема: Линейные списки
2. Цель работы: составить и отладить программу на языке Си для обработки линейного списка с отображением на динамичесике структуры. Навигацию осуществлять с помощью итереаторов.
3. Задание: составить линейный однонаправленный список из машинных слов, а также функцию удаления из списка всех элементов, предшествующих и последующих данному значению.
4. Идея, метод, алгоритм решения задачи:
 - взять за основу готовый код из условия задания;
 - ввод данных отчасти скатать из 26 лабы, отчасти придумать заново;
 - печать из условия;
 - длина из печати;
 - удаление не нужно при мне упоминать, там пришлось много думать.
  В принципе, из идей всё.
5. Сценарий выполнения работы:
- будем предельно откровенны, взять основу кода из Github, что даёт нам инициализацию списка и итераторов, а также  часть функций с итераторами;
 - остальное оказалось хламом, нужно делать самим;
 - сначала сделать нормальный ввод, чтобы он не тёк и с его помощью можно было легко удалять потом;
 - потом распечатать список и его длину;
 - потом самое сложное: удалить элемент из списка, не снеся valgrind-у башню (а я её ему снёс);
 - таки написать это удаление и сделать на его основе удаление элементов по заданию;
 - вспомнить про проклятые итераторы и переписать функции под них;
6. Протокол:
   Прикреплён отдельным файлом (большой слишком)
8: Выводы: Шиндлеру было явно проще написать свой список, чем мне. По крайней мере, у меня ушло на это больше одного дня. Программа работает, к счастью, не течёт, и с этими утечками мне было справиться чуть легче, чем в прошлых лабах. Опыт всё-таки начал появляться, да и отладчик тоже сильно помогать стал. На этом свой маленький отчёт закончу. 