# Utiliser une base Debian stable
FROM debian:bullseye

# Installer PHP, ses extensions nécessaires
RUN apt-get update && apt-get upgrade && apt-get install -y \
    wget \
    php7.3 \
    php-fpm \
    php-mysql \ 
    mariadb-client && rm -rf /var/lib/apt/lists/*

# Install wp_cli m| Pernmets d'eviter la page de config de Worpress
RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
    && chmod +x wp-cli.phar \
    && mv wp-cli.phar /usr/local/bin/wp


RUN mkdir -p /run/php  /var/www/html

#Copy the script, asdd right to execute 
COPY ./tools/conf/wordpress_conf.sh /usr/local/bin
RUN chmod +x /usr/local/bin/wordpress_conf.sh
ENTRYPOINT ["/usr/local/bin/wordpress_conf.sh"]

WORKDIR /var/www/html

EXPOSE 9000

ENTRYPOINT ["/usr/local/bin/wordpress_conf.sh"]