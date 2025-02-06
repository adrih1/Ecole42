set -e

if [ ! -d "/var/lib/mysql/mysql" ]; then
    echo "Initializing database..."
    
    chown -R mysql:mysql /var/lib/mysql
    chmod 750 /var/lib/mysql

    mariadb-install-db --user=mysql --datadir=/var/lib/mysql --basedir=/usr

    echo "Database initialized."
fi

if [ ! -d "/var/lib/mysql/${SQL_DATABASE}" ]; then
    echo "Setting up initial database..."

    # Crée un fichier SQL temporaire pour configurer la base de données
    cat << EOF > /tmp/create_db.sql
USE mysql;
FLUSH PRIVILEGES;
DELETE FROM mysql.user WHERE User='';
DROP DATABASE IF EXISTS test;
DELETE FROM mysql.db WHERE Db='test' OR Db='test_%';
DELETE FROM mysql.user WHERE User='root' AND Host NOT IN ('localhost', '127.0.0.1', '::1');
ALTER USER 'root'@'localhost' IDENTIFIED BY '${SQL_ROOT_PASSWORD}';
CREATE DATABASE \`${SQL_DATABASE}\` CHARACTER SET utf8 COLLATE utf8_general_ci;
CREATE USER '${SQL_USER}'@'%' IDENTIFIED BY '${SQL_PASSWORD}';
GRANT ALL PRIVILEGES ON \`${SQL_DATABASE}\`.* TO '${SQL_USER}'@'%';
FLUSH PRIVILEGES;
EOF

    # Applique les changements via MariaDB en mode bootstrap
    mysqld --user=mysql --bootstrap < /tmp/create_db.sql
    rm -f /tmp/create_db.sql

    echo "Initial database setup complete."
fi

# Démarre MariaDB
exec mysqld --user=mysql
