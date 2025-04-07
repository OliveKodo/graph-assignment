
בניית גרף באמצעות רשימת שכנויות

על הקוד:
מימשתי גרף לא מכוון עם רשימת שכנויות בלי STL. הכוללים את כל מבני הנתונים הנדרשים (תור, תור עדיפויות, Union-Find) אלגוריתמים לעבודה עם הגרפים.

יש בקוד:
- Graph - מבני נתונים לגרף הכולל הוספה והסרת קשתות.
- Queue - מימוש תור פשוט (FIFO) עבור BFS.
- PriorityQueue - תור עדיפויות מבוסס ערימה עבור Dijkstra ו-Prim.
- UnionFind - מבנה נתונים לרכיבים קשירים שמשמש ב-Kruskal.
- Algorithms - מימוש של: BFS, DFS, Dijkstra, Prim, Kruskal.

איך להריץ:
יש קובץ Makefile:
- `make Main` - להידור והרצת דוגמה.
- `make test` - להרצת בדיקות עם doctest.
- `make valgrind` - לבדיקת דליפות זיכרון.
- `make clean` - לניקוי קבצי קומפילציה.

פיצ'רים:
- כתיבת כל מבני הנתונים מאפס (בלי STL).
- ניהול זיכרון טוב, נבדק עם Valgrind.
- בדיקות מקיפות כולל מקרי קצה (באמצעות doctest).

