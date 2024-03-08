#!/bin/bash
cd /d/D
read -p "Введите название каталога: "  catalog

if [ -s $catalog ];
then
    echo "Вы ввели какую-то фигню, дальше работаем с диском D";
    catalog="D"; 
else 
    while [ -s $(find . -type d -name "$catalog") ];
    do 
        echo "Эмм... Вы ввели что-то не то, попробуйте ещё раз";
        read catalog;
    done;
fi

main_catalog=$catalog;

function rewrite {
    cd "$(find /d/D -name "$catalog")";
    for arg in $(ls -R $(find /d/D -name "$catalog"));
    do
        if [ -d $arg ];
        then
            catalog=$arg;
            rewrite;
        else
            if [ $arg = "Makefile" ];
            then
                touch file.txt;
                cat $arg | tr '/' '\\' > file.txt;
                cat file.txt > $arg;
                rm -f file.txt;
            fi;
        fi;
    done
    if [ $catalog != $main_catalog ];
    then
        cd ..;
        catalog=$(pwd | awk -F'/' '{print $NF}');
        fi;
}

rewrite;

#First_directory
#https://habr.com/ru/companies/ruvds/articles/325522/
#https://losst.pro/funktsii-bash-v-skriptah?ysclid=ltg1zc7zsc444847372
#https://itsecforu.ru/2022/09/14/%F0%9F%90%A7-%D0%BF%D0%BE%D0%BB%D1%83%D1%87%D0%B5%D0%BD%D0%B8%D0%B5-%D0%B0%D0%B1%D1%81%D0%BE%D0%BB%D1%8E%D1%82%D0%BD%D0%BE%D0%B3%D0%BE-%D0%BF%D1%83%D1%82%D0%B8-%D0%BA-%D1%84%D0%B0%D0%B9%D0%BB%D1%83/
#https://losst.pro/gerp-poisk-vnutri-fajlov-v-linux?ysclid=ltfexf602f470616812
#https://habr.com/ru/companies/ruvds/articles/327530/