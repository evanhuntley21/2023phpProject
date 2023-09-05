FROM public.ecr.aws/docker/library/php:apache
COPY ./public-html/ /var/www/html
RUN docker-php-ext-install mysqli
