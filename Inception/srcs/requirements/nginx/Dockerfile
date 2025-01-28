# Utiliser l'avant derniere version stable
FROM debian:bullseye

RUN apt-get update && apt-get install -y nginx openssl && \
    mkdir -p /var/run/nginx && \
	mkdir -p /etc/nginx/certs && \
    mkdir -p /var/www/html && \
    chmod 755 /var/www/html && \
    chown -R www-data:www-data /var/www/html



# Copier le fichier de configuration nginx
COPY ./tools/conf/nginx.conf /etc/nginx/nginx.conf

# Copier les fichiers du site (index.html et styles.css)
COPY ./tools/html /var/www/html

# Copier les certificats SSL
COPY ./tools/certs/server.crt /etc/nginx/certs
COPY ./tools/certs/server.key /etc/nginx/certs

# Exposer le port HTTPS
EXPOSE 443

# Lancer nginx en avant-plan
CMD ["nginx", "-g", "daemon off;"]
