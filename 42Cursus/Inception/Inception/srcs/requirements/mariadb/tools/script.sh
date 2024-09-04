#!/bin/bash

echo "------------------------------- MARIADB START -------------------------------------"

echo "=>0"

service mysql start;

echo "=>1"

# mysql -e "CREATE USER IF NOT EXISTS \`${SQL_USER}\`@'localhost' IDENTIFIED BY '${SQL_PASSWORD}';"
# mysql -e "GRANT ALL PRIVILEGES ON \`${SQL_DATABASE}\`.* TO \`${SQL_USER}\`@'%' IDENTIFIED BY '${SQL_PASSWORD}';"
# mysql -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${SQL_ROOT_PASSWORD}';"
# mysql -e "FLUSH PRIVILEGES;"

mysql -u root -p${SQL_ROOT_PASSWORD} -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${SQL_ROOT_PASSWORD}';"
echo "=>1.1"
mysql -u root -p${SQL_ROOT_PASSWORD} -e "CREATE DATABASE IF NOT EXISTS ${SQL_DATABASE};"
echo "=>1.2"
mysql -u root -p${SQL_ROOT_PASSWORD} -e "CREATE USER IF NOT EXISTS '${SQL_USER}' IDENTIFIED BY '${SQL_ROOT_PASSWORD}';"
echo "=>1.3"
mysql -u root -p${SQL_ROOT_PASSWORD} -e "GRANT ALL PRIVILEGES ON *.* TO '${SQL_USER}';"
echo "=>1.4"
mysql -u root -p${SQL_ROOT_PASSWORD} -e "FLUSH PRIVILEGES;"
echo "=>1.5"

mysqladmin -u root -p$SQL_ROOT_PASSWORD shutdown
echo "=>2"
exec mysqld_safe
