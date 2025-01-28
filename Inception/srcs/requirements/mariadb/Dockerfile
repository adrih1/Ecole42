FROM debian:bullseye

# Mettre à jour le système et installer MariaDB Server
RUN apt-get update && apt-get upgrade -y && apt-get install -y \
    mariadb-server \
    nano && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

COPY ./tools/conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

COPY tools/init-db.sh /init-db.sh

RUN mkdir -p /var/lib/mysql /var/run/mysqld && \
    chown -R mysql:mysql /var/lib/mysql /var/run/mysqld && \
    chmod 750 /var/lib/mysql /var/run/mysqld

RUN mariadb-install-db --user=mysql --datadir=/var/lib/mysql --basedir=/usr

EXPOSE 3306

ENTRYPOINT ["bash", "./tools/init-db.sh"]