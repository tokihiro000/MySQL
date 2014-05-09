#include "INVARIABLE_MACRO.h"

char *make_sql_query(int instruction, char *table, unsigned char *value_1, unsigned char *value_2, unsigned char *value_3) {
  char *query;
  unsigned char *hex_val_1, *hex_val_2, *hex_val_3;
  int i;

  query = (char *)malloc(sizeof(char) * 200);
  memset(query, 0x00, sizeof(char) * 200);

  switch (instruction) {
  case SELECT:
    strcpy(query, "select * from ");
    strcat(query, table);
    return query;
    break;

  case INSERT:
    strcpy(query, "insert into ");
    strcat(query, table);
    strcat(query, " values('");

    hex_val_1 = bin_to_hex(value_1, 32);
    strcat(query, (char *)hex_val_1);
    free(hex_val_1);

    strcat(query, "', '");

    hex_val_2 = bin_to_hex(value_2, 32);
    strcat(query,  (char *)hex_val_2);
    free(hex_val_2);

    strcat(query, "')");

    printf("strlen(query) = %lu\nquery = %s\n", strlen(query), query);
    return query;
    break;

  case DELETE:
    break;

  case UPDATE:
    break;

  default:
    return NULL;
    break;
  }

  return NULL;
}

MYSQL_RES *use_sql (MYSQL *conn, int instruction, char *table, unsigned char *value_1, unsigned char *value_2, unsigned char *value_3) {
  char *query;
  MYSQL_RES *res;

  query = make_sql_query(instruction, table, value_1, value_2, value_3);

  if (query == NULL) {
    printf("クエリの作成に失敗\n");
    return NULL;
  }

  if (mysql_query(conn, query)) { //←Queryを記述
    printf("SQL error\n");
    fprintf(stderr, "%s\n", mysql_error(conn));
    free(query);
    return NULL;
  }

  res = mysql_store_result(conn);
  free(query);

  //mysql_close(conn);

  return res;

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

}
