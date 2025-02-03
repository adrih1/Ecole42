#!/bin/bash

# Attendre que le service MariaDB soit prêt
sleep 5

if [ -f ./wp-config.php ]; then
    echo "WordPress is already configured."
else
    echo "Downloading and configuring WordPress..."

    # Télécharger WordPress
    wp core download --path=/var/www/html --allow-root

    # Configurer WordPress
    if [! -f wp-config.php] ; then
        echo "Creating wp-config.php ..."
        wp config create \ 
            --dbname="${SQL_DATABASE}" \ 
            --dbuser="${SQL_USER}" \
            --dbpass="${SQL_PASSWORD}" \ 
            --dbhost="${MYSQL_HOST}" \ 
            --path=/var/www/html  \
            --allow-root
    fi

    if ! wp core is-installed --allow-root; then
        echo "Installing Wordpress"
        wp core install 
            --url= localhost \  
            --title="${WP_TITLE}" \
            --admin_user="${WP_ADMIN_USER}" \
            --admin_password="${WP_ADMIN_PASSWORD}" \ 
            --admin_email="${WP_ADMIN_EMAIL}" \
            --path=/var/www/html \
            --allow-root
        echo "Creating user $WP_USER ..."
        wp user create \
            $WP_USER $WP_USER_EMAIL \
            --role=editor \
            --user_paas=$WP_ADMIN_PASSWORD \
            --allow-root
    echo "WordPress setup complete!"
fi


# Garder le conteneur actif
exec php-fpm -F 
