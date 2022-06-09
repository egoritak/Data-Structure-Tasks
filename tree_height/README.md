# Задание

## Высота дерева
***Вычислить высоту данного дерева.***
**Вход:** 

    Корневое дерево с вершинами {0, . . . , n−1}, заданное как последовательность parent0, . . . , parentn−1, где parent[i] — родитель i-й вершины.
**Выход:**

    Высота дерева.
 
 ***Формат входа.*** 
    
    Первая строка содержит натуральное число n. Вторая строка содержит n целых чисел parent0, . . . , parentn−1. Для каждого 0 ≤ i ≤ n−1, parent[i] — родитель вершины i; если parenti = −1, то i является корнем.
    Гарантируется, что корень ровно один. Гарантируется, что данная последовательность задаёт дерево.
    
***Формат выхода.***
    
    Высота дерева.
    
***Ограничения.***

    1 ≤ n ≤ 105

***Примеры:***

**Вход:**

    5
    4 -1 4 1 1

![alt text](https://psv4.userapi.com/c235031/u157736282/docs/d15/f28ef399f69e/Screenshot_from_2022-06-08_23-42-58.png?extra=rq2LpBUYzO2hUuwFPqzuQ-Fj_QdPbg4f4istZ1oMSJmys92VbXCd2lVhl_qkes5NE3HHDGXW4-IXlQoJb4ONBGe6PSRt9xnLlxUbUJoWO0-pAeaPKH3tzWeG84uu53YLBrrdmw-1CpXUO4Kp7RAI7KWh)

**Выход:**

    3
    
**Вход:**

    5
    -1 0 4 0 3
![alt text](https://psv4.vkuseraudio.net/s/v1/d/k-QTZiibP-9JSRhPMuTQ8HCHhX5mGaJ5Fhc9ThedhqdgUR_BRTuJtK7-eiXxMm6KWYKTtQ9ZOXH1L4zU0vtgY6NiV9L8mz3zdL4jGUfJS6JaRDWUtmHXtA/Screenshot_from_2022-06-08_23-43-08.png)

**Выход:**

    4
