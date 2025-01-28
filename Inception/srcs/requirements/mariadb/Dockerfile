FROM debian:bullseye

# Mettre à jour le système et installer MariaDB Server
RUN apt-get update && apt-get upgrade -y && apt-get install -y \
    mariadb-server \
    vim && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

