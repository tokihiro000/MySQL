#include "INVARIABLE_MACRO.h"

MYSQL *sql_connector() {
  MYSQL *conn;

  // 接続
  conn = mysql_init(NULL);
  if (!mysql_real_connect(conn, MYSQL_SERVER, MYSQL_USERNAME, MYSQL_PASSWORD, MYSQL_DATEBASE, 3306, NULL, 0)) {
    fprintf(stderr, "%s\n", mysql_error(conn));
    return NULL;
  }

  return conn;
}
