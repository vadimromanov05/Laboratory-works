#!/bin/bash
cd /d/D
read -p "Введите название каталога: "  catalog
if [ -s $catalog ]; then echo "Вы ввели какую-то фигню, дальше работаем с диском D"; catalog="D"; else while [ -s $(find . -type d -name "$catalog") ]; do echo "Эмм... Вы ввели что-то не то, попробуйте ещё раз"; read catalog; done; fi
for arg in $(find /d/D -name "$catalog"); do echo -e "$(find $(find /d/D -name "$catalog") -name 'Makefile')" | tr '/' '\\'; echo -e "$(find $(find /d/D -name "$catalog") -not -name 'Makefile')"; done