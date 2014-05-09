#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>
#include "memcat.c"
#include "pseudo_random.c"


#define MYSQL_SERVER "localhost"
#define MYSQL_USERNAME "Kyunn"
#define MYSQL_PASSWORD "tokihiro3462"
#define MYSQL_DATEBASE "sse"

int main() {
  int num_fields;
  int i, j, r, c;
  unsigned char *random;
  MYSQL_FIELD *fields;
  MYSQL *conn;
  MYSQL_RES *res;
  MYSQL_ROW row;
  char query[100] = "insert into test values(8, '";
  char *tozi = "')";


  random = pseudo_random(10);
  memcat(query, tozi, random, 10);
  printf("[query]=%s\n", query);
  // 接続
  conn = mysql_init(NULL);
  if (!mysql_real_connect(conn, MYSQL_SERVER, MYSQL_USERNAME, MYSQL_PASSWORD, MYSQL_DATEBASE, 3306, NULL, 0)) {
    fprintf(stderr, "%s\n", mysql_error(conn));
    exit(1);
  }

  if (mysql_query(conn, query)) { //←Queryを記述
    fprintf(stderr, "%s\n", mysql_error(conn));
    exit(1);
  }
  res = mysql_store_result(conn);

  // 結果表示
  /* r = mysql_num_rows(res);//←今回の場合、テーブルのレコード数 */
  /* c = mysql_num_fields(res);//←今回の場合、フィールド数 */
  /* for (i = 0; i < r; i++) { */
  /*   printf("> "); */
  /*   row = mysql_fetch_row(res); //←フィールド名も含まれるらしいので、いきなり次列 */
  /*   for (j = 0; j < c; j++) { */
  /*     if (j != 0) { */
  /*       printf(","); */
  /*     } */
  /*     if (row[j] != NULL) { */
  /*       printf("\"%s\"", row[j]); */
  /*     } */
  /*     else { */
  /*       printf("\"NULL\""); */
  /*     } */
  /*   } */
  /*   printf("\n"); */
  /* } */

  // 切断
  mysql_close(conn);
}
