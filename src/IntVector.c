#include "IntVector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

IntVector *int_vector_new(size_t initial_capacity) {
  IntVector *t = malloc(sizeof(IntVector)); // Выделяем память для структуры
  if (t == NULL) // Если память выделить не удалось
    return NULL; // Возвращаем NULL
  t->pointer =
      malloc(initial_capacity *
             sizeof(int)); // Выделяем память для массива внутри структуры
  if (t->pointer == NULL) { // Если память выделить не удалось
    free(t); // Освобождаем память для структуры
    return NULL; // Возвращаем NULL
  }
  t->size = 0;
  t->capacity = initial_capacity;
  return t;
}

IntVector *int_vector_copy(const IntVector *v) {
  IntVector *t = malloc(sizeof(IntVector)); // Выделяем память для структуры
  if (t == NULL)
    return NULL;
  t->pointer =
      malloc(v->capacity *
             sizeof(int)); // Выделяем память для массива внутри структуры
  if (t->pointer == NULL) {
    free(t);
    return NULL;
  }
  memcpy(t->pointer, v->pointer,
         sizeof(int) * v->capacity); // Копируем байты из *v в *t
  t->size = v->size; // Значение размера вектора v копируем в вектор t
  t->capacity = v->capacity; // С ёмкостью делаем то же самое
  return t;
}

void int_vector_free(IntVector *v) {
  free(v->pointer); // Освобождаем память для массива внутри структуры
  free(v);          // И для самой структуры
}

int int_vector_get_item(const IntVector *v, size_t index) {
  return v->pointer[index]; // Выводим элемент с выбранным индексом
}

void int_vector_set_item(IntVector *v, size_t index, int item) {
  if (index <= v->capacity) // Если индекс меньше либо равен ёмкости
    v->pointer[index] = item; // Присваиваем элементу выбранное значение
  if (index >= v->size) // Если индекс больше либо равен размеру
    v->size++; // Увеличиваем размер на единицу
}

size_t int_vector_get_size(const IntVector *v) {
  return v->size; // Возвращаем размер вектора
}

size_t int_vector_get_capacity(const IntVector *v) {
  return v->capacity; // Возвращаем ёмкость вектора
}

int int_vector_push_back(IntVector *v, int item) {
  if (v->size < v->capacity) {
    v->pointer[v->size] = item; // Добавляем элемент в конец массива и
                                // присваиваем ему выбранное значение
    v->size++;        // Увеличиваем размер на единицу
  } else {            // Если размер не меньше ёмкости
    v->capacity *= 2; // Коэффицент роста
    int *t = malloc(v->capacity *
                    sizeof(int)); // Выделяем память для удвоенной ёмкости
    for (int i = 0; i < v->size; i++) {
      t[i] = v->pointer[i]; // Сохраняем значения массива внутри структуры
    }

    free(v);
    v->pointer = t;
    v->pointer[v->size] = item;
    v->size++;
  }
  return 0;
}

void int_vector_pop_back(IntVector *v) {
  if (v->size != 0)
    (v->size)--; // Уменьшаем размер на единицу
}

int int_vector_shrink_to_fit(IntVector *v) {
  if (v->size < v->capacity) {
    v->capacity = v->size; // Присваиваем ёмкости значение размера структуры
    int *t =
        realloc(v->pointer, v->size * sizeof(int)); // Уменьшаем блок памяти
    if (t == NULL) // Если уменьшить не удалось
      return -1;
    v->pointer = t; // Берём указатель на новый блок памяти
    return 0;
  }
  return -1;
}

int int_vector_resize(IntVector *v, size_t new_size) {
  if (new_size == v->size)
    return 0;
  if (new_size > v->size) {
    int *t =
        realloc(v->pointer, new_size * sizeof(int)); // Увеличиваем блок памяти
    if (t == NULL)
      return -1;
    v->pointer = t;
    for (int i = new_size - v->size; i < new_size; i++) // Для новых элементов
      v->pointer[i] = 0; // Присваиваем нули
  }
  v->size = new_size;
  v->capacity = new_size;
  return 0;
}

int int_vector_reserve(IntVector *v, size_t new_capacity) {
  if (new_capacity > v->capacity) {
    v->capacity = new_capacity;
    int *t = realloc(
        v->pointer,
        new_capacity * sizeof(int)); // Увеличиваем блок памяти на новую ёмкость
    if (t == NULL)
      return -1;
    v->pointer = t;
    return 0;
  }
  return -1;
}
