# Utiliser une base Debian stable
FROM debian:bullseye

# Installer PHP, ses extensions nécessaires
RUN apt-get update && apt-get install -y \
    wget \
    php7.3 \
    php-fpm \
    php-mysql \ 
    mariadb-client 

# Télécharger Wordpress
RUN wget https://fr.wordpress.org/wordpress-6.0-fr_FR.tar.gz -P /var/www

# Extraire WordPress
RUN cd /var/www && tar -xzf wordpress-6.0-fr_FR.tar.gz && rm wordpress-6.0-fr_FR.tar.gz

# Donner les droits
RUN		chown -R root:root /var/www/wordpress

# Lancer PHP-FPM en mode foreground
CMD ["php-fpm", "-F"]
