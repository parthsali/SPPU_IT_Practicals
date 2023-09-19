#!/bin/bash

fileExists(){
    if [ ! -e Address_Book.txt ];
    then 
        
        return 1
    fi
}

createAddressBook(){
    if [ ! -e Address_Book.txt ];
    then 
        touch Address_Book.txt 
    fi
    echo "| Name | Email | Phone Number | Address |" > Address_Book.txt
}

viewAddressBook(){
    if [ ! -e Address_Book.txt ];
    then 
        echo "Address Book is Not Created. First Create Address Book"
        return
    fi

    if [ -s Address_Book.txt ];
    then
        cat Address_Book.txt
    else
        echo "Address Book is Empty"
    fi
}

insertRecord(){
    if [ ! -e Address_Book.txt ];
    then 
        echo "Address Book is Not Created. First Create Address Book"
        return
    fi

    read -p "Enter Name: " name
    read -p "Enter Email: " email
    read -p "Enter Phone Number: " phone
    read -p "Enter Address: " address

    
    echo "| $name | $email | $phone | $address |" >> Address_Book.txt

}

deleteRecord(){
    if [ ! -e Address_Book.txt ];
    then 
        echo "Address Book is Not Created. First Create Address Book"
        return
    fi

    read -p "Enter Name: " name
    if [ -z "$(grep -i $name Address_Book.txt)" ];
    then
        echo "Record Not Found"
    else
        sed -i "/$name/d" Address_Book.txt
    fi
}

searchRecord(){
    if [ ! -e Address_Book.txt ];
    then 
        echo "Address Book is Not Created. First Create Address Book"
        return
    fi

    read -p "Enter Name: " name
    if [ -z "$(grep -i $name Address_Book.txt)" ];
    then
        echo "Record Not Found"
    else
        grep -i $name Address_Book.txt
    fi
}

updateRecord(){
    if [ ! -e Address_Book.txt ];
    then 
        echo "Address Book is Not Created. First Create Address Book"
        return
    fi

    read -p "Enter Name: " name

    if [ -z "$(grep -i $name Address_Book.txt)" ];
    then
        echo "Record Not Found"
        return
    fi

    sed -i "/$name/d" Address_Book.txt
    read -p "Enter Email: " email
    read -p "Enter Phone Number: " phone
    read -p "Enter Address: " address
    echo "| $name | $email | $phone | $address |" >> Address_Book.txt
}

main(){
    while true;
    do
        echo -e "\nWelcome to Address Book\n"
        echo "1. Create Address Book"
        echo "2. View Address Book"
        echo "3. Insert Record"
        echo "4. Delete Record"
        echo "5. Search Record"
        echo "6. Update Record"
        echo -e "7. Exit\n"

        read -p "Enter Choice: " choice

        case $choice in
            1)
            createAddressBook
            ;;
            2)
            viewAddressBook
            ;;
            3)
            insertRecord
            ;;
            4)
            deleteRecord
            ;;
            5)
            searchRecord
            ;;
            6)
            updateRecord
            ;;
            7)
            exit
            ;;
            *)
            echo "Invalid Choice"
            ;;
        esac
    done
}

main