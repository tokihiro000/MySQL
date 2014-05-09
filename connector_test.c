#include <stdio.h>
#include <string.h>
#include <mysql.h>
#include "INVARIABLE_MACRO.h"
#include "bin_to_hex.c"
#include "sql_connector.c"
#include "use_sql.c"
#include "pseudo_random.c"



int main(void) {
  int num_fields;
  int i, j, r, c;
  MYSQL_FIELD *fields;
  MYSQL_ROW row;
  MYSQL_RES *res;
  MYSQL *conn;
  int result;
  unsigned char *r1, *r2;

  conn = sql_connector();
  if (conn == NULL) {
    printf("DB connect error\n");
    exit(1);
  }

  r1 = pseudo_random(32);
  r2 = pseudo_random(32);
  res = use_sql(conn, INSERT, "Ts_test", r1, r2, NULL);

  if (res == NULL) {
    mysql_close(conn);
    free(r1);
    free(r2);
    exit(0);
  }


  //結果表示
  r = mysql_num_rows(res);//←今回の場合、テーブルのレコード数
  c = mysql_num_fields(res);//←今回の場合、フィールド数
  for (i = 0; i < r; i++) {
    printf("> ");
    row = mysql_fetch_row(res); //←フィールド名も含まれるらしいので、いきなり次列
    for (j = 0; j < c; j++) {
      if (j != 0) {
        printf(",");
      }
      if (row[j] != NULL) {
        printf("\"%s\"", row[j]);
      }
      else {
        printf("\"NULL\"");
      }
    }
    printf("\n");
  }

  // 切断
  mysql_close(conn);

  free(r1);
  free(r2);
  return 0;
}
