# source: Fhttps://github.com/FXC-ai/Inception/blob/main/srcs/requirements/wordpress/tool/start_wdp.sh
echo "------------------------------- WORDPRESS START -----------------------------------"

php-fpm7.3 -v

# Boucle verification mariadb
while ! mariadb -u $SQL_USER --password=$SQL_PASSWORD -h mariadb -P 3306 --silent; do
	sleep 1
	echo "Mariadb n'est pas encore pret"
done

# Affichage dans le terminal des bases de donnees
echo "------------------\n"
mariadb -u $SQL_USER --password=$SQL_PASSWORD -h mariadb -P 3306 -e "SHOW DATABASES;"
echo "------------------\n"


# Installation de Wordpress si necessaire
if [ -e /var/www/wordpress/wp-config.php ]
then echo "wp-config existe."
else

	# Installation de wp-cli
	wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
	chmod +x wp-cli.phar
	mv wp-cli.phar /usr/local/bin/wp

	# Installation de wordpress
	cd /var/www/wordpress
	wp core download --allow-root

	Configuration de wordpress : connection a la base de donnees et creation des users de wordpress
	wp config create --dbname=$SQL_DATABASE --dbuser=$SQL_USER --dbpass=$SQL_PASSWORD --dbhost=$WP_HOST --dbcharset="utf8" --dbcollate="utf8_general_ci" --allow-root
	wp core install --url=$DOMAIN_NAME --title=$WP_TITLE --admin_user=$WP_ADMIN_USER --admin_password=$SQL_ROOT_PASSWORD --admin_email=$SQL_ADMIN_EMAIL --skip-email --allow-root
	wp user create $SQL_USER $WP_USER_EMAIL --role=author --user_pass=$SQL_PASSWORD --allow-root

fi

# Lancement de php-fpm
php-fpm7.3 -F
