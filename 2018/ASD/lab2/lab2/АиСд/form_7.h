#if !defined(__FORM7_H)
   #define __FORM7_H
     //const ...; // Определение исключительных ситуаций
     typedef struct str
                 {
                    char *s; /* Указатель на строку. Первые два байта строки s содержат динамическую длину строки */
                    unsigned max; /* Максимальное количество символов в строке, определяющееся при инициализации */
                  };
     typedef str *string1;
       void InitStr(string1 st, unsigned n);
       dvoid WriteFromStr(char *s, string1 st);
       void InputStr(string1 st);
       void OutputStr(string1 st);
       int Comp(string1 s1, string1 s2);
       void Delete(string1 s, unsigned Index, unsigned Count);
       void Insert(string1 Subs, string1 s, unsigned Index);
       void Concat(string1 s1, string1 s2, string1 srez);
       void Copy(string1 s, unsigned Index, unsigned Count,string1 Subs);
       unsigned Length(string1 s);
       unsigned Pos(string1 SubS, string1 s);
       void DoneStr(string1 s);
       int StrError; // Переменная ошибок//...
   #endif
