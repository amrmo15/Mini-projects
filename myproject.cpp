#include <iostream>
#include <fstream>
using namespace std ;

class mymarket
{
    public : 
    void main_menu()
    {
    cout << "#######################################################\n" ;
    cout << "                                                       \n" ;
    cout << "               welcome to my market                    \n" ;
    cout << "                                                       \n" ;
    cout << "#######################################################\n" ;
    cout << "1] admin \n" ;
    cout << "2] buyer \n" ;
    cout << "3] exit  \n" ;

    int choise ;
    cin >> choise ;

    switch (choise)
    {
    
    case 1 :
    system("cls") ;
    check_admin() ;
    break;

    case 2 :
    system("cls") ;
    buyer() ;
    break;

    case 3 :
    system("cls") ;
    exit_screen() ;
    exit(0) ;
    break;
    
    default:
    {
    system("cls") ;
    wrong_choise_screen() ;

    int answer ;
    cin >> answer ;

    switch (answer)
    {

    case 1 :
    system("cls") ;
    main_menu() ;
    break;

    case 2 :
    system("cls") ;
    exit_screen() ;
    exit(0) ;
    break;
    
    default:
    system("cls") ;
    exit_screen() ;
    break;
    }
    }
    break;

}  
}
    void admin()
    {
    cout << "#######################################################\n" ;
    cout << "                                                       \n" ;
    cout << "                      welcome admin                    \n" ;
    cout << "                                                       \n" ;
    cout << "#######################################################\n" ;
    cout << "1] add product              \n" ;
    cout << "2] edit product             \n" ;
    cout << "3] delete product           \n" ;
    cout << "4] exit                     \n" ;

    int choise ;
    cin >> choise ;

    switch (choise)
    {
    
    case 1 :
    system("cls") ;
    add_product() ;
    break;

    case 2 :
    system("cls") ;
    edit_product() ;
    break;

    case 3 :
    system("cls") ;
    delete_product() ;
    break;

    case 4 :
    system("cls") ;
    exit_screen() ;
    exit(0) ;
    break;
    
    default:
    system("cls") ;
    wrong_choise_screen() ;

    int choise ;
    cin >> choise ;

    switch(choise)
    {
    case 1 :
    system("cls") ;
    main_menu() ;
    break;

    case 2 :
    system("cls") ;
    exit_screen() ;
    exit(0) ;
    break;

    default :
    system("cls") ;
    exit_screen() ;
    exit(0) ;
    break;
    }

    break;
    }

    }
    void add_product()
    {
    
    fstream database ;
    database.open("database.txt" , ios::in) ;

    if (!database || (database.peek() == EOF))
    {
        empty_database_screen() ;
    }
    else
    {
    market_data() ;
    }
    database.close() ;
    cout << "#######################################################\n" ;
    cout << "                                                       \n" ;
    cout << "                  enter product data                   \n" ;
    cout << "                                                       \n" ;
    cout << "#######################################################\n" ;

    int product_code ;
    int product_price ;
    string product_name ;
    float product_disscount ;

    cout << "enter product name \n" ;
    cin >> product_name ;

    cout << "enter product code \n" ;
    cin >> product_code ;

    cout << "enter product price \n" ;
    cin >> product_price ;

    cout << "enter discount ( if there is no discount input 0) \n" ;
    cin >> product_disscount ;

    database.open("database.txt" , ios::out | ios::app) ;

    database << " " << product_name << " " << product_code << " " << product_price << " " << product_disscount << "\n" ; 
    database.close() ;
    
    system("cls") ;
    product_added_sucessfully() ;

    cout << "1] add another product \n" ;
    cout << "2] back to admin menu   \n" ;
    cout << "3] back to main menu   \n" ;
    cout << "4] exit                \n" ;

    int choise ;
    cin >> choise ;

    switch (choise)
    {
    
    case 1 :
    system("cls") ;
    add_product() ;
    break;

    case 2 :
    system("cls") ;
    admin() ;
    break;

    case 3 :
    system("cls") ;
    main_menu() ;
    break;

    case 4 :
    system("cls") ;
    exit_screen() ;
    exit(0) ;
    
    default:
    system("cls") ;
    wrong_choise_screen() ;

    int choise ;
    cin >> choise ;

    switch (choise)
    {
    
    case 1 :
    system("cls") ;
    main_menu() ;
    break;

    case 2 :
    system("cls") ;
    exit_screen() ;
    exit(0) ;
    break;
    
    default:
    break;
    }

    break;
    }


    }
    void edit_product()
    {
    
    fstream database ;
    database.open("database.txt" , ios::in) ;

    if (!database || database.peek() == -1)
    {
        empty_database_screen() ;
        cout << "1] main menu  \n" ;
        cout << "2] admin menu \n" ;
        cout << "3] exit       \n" ;

        enum enChoises{Main=1 , Admin , Exit} ;
        int choise ;
        cin >> choise ;

        switch (choise)
        {
        
        case Main :
        system("cls") ;
        main_menu() ;
        break;

        case Admin :
        system("cls") ;
        admin() ;
        break;

        case Exit :
        system("cls") ;
        exit_screen() ;
        exit(0) ;
        break;

        default:
        break;
        }
    }
    else
    {
    market_data() ;
    cout << "#######################################################\n" ;
    cout << "                                                       \n" ;
    cout << "                  enter product code                   \n" ;
    cout << "                                                       \n" ;
    cout << "#######################################################\n" ;

    int search_product_code ;
    cin >> search_product_code ;

    int product_code ;
    int product_price ;
    string product_name ;
    float product_disscount ; 

    fstream new_data_base ;
    new_data_base.open("new_data_base.txt" , ios::out|ios::app) ;

    string new_name ;
    int new_code ;
    int new_price ;
    float new_discount ;




    bool is_edited = 0 ;
    while (database >> product_name >> product_code >> product_price >> product_disscount)
    {
        if (search_product_code == product_code)
        {
            cout << "enter new name \n" ;
            cin >> new_name ;

            cout << "enter new code \n" ;
            cin >> new_code ;

            cout << "enter new price \n" ;
            cin >> new_price ;

            cout << "enter new discount ( if there is no discount input 0 ) \n" ;
            cin >> new_discount ;

            new_data_base << " " << new_name << " " << new_code << " " << new_price << " " << new_discount << "\n" ;


            is_edited = 1 ;
        }

        else
        {
              new_data_base << " " << product_name << " " << product_code << " " << product_price << " " << product_disscount << "\n" ;
        }

    }

    database.close() ;
    new_data_base.close() ;
    remove("database.txt") ;
    rename("new_data_base.txt" , "database.txt") ;

    if (!is_edited)
    {
    system("cls") ;
    cout << "#########################################\n" ;
    cout << "there is no code like this in data base  \n" ;
    cout << "#########################################\n" ;
    cout << "1] edit another product     \n" ;
    cout << "2] back to admin menu       \n" ;
    cout << "3] back to main menu        \n" ;
    cout << "4] exit                     \n" ;

    int choise ;
    cin >> choise ;

    switch (choise)
    {
    
    case 1 :
    system("cls") ;
    edit_product() ;
    break;

    case 2 :
    system("cls") ;
    admin() ;
    break;

    case 3 :
    system("cls") ;
    main_menu() ;
    break;

    case 4 :
    system("cls") ;
    exit_screen() ;
    exit(0) ;
    break;
        
    default:
    system("cls") ;
    wrong_choise_screen() ;

    int choise ;
    cin >> choise ;

    switch(choise)
    {

    case 1 :
    system("cls") ;
    main_menu() ;
    break;

    case 2 :
    system("cls") ;
    exit_screen() ;
    exit(0) ;
    break;

    default :
    system("cls") ;
    exit_screen() ;
    exit(0) ;
    break;
    }

    break;
    }


    }


    else
    {

    system("cls") ;
    product_edited_sucessfully() ;

    cout << "1] edit another product     \n" ;
    cout << "2] back to admin menu       \n" ;
    cout << "3] back to main menu        \n" ;
    cout << "4] exit                     \n" ;

    int choise ;
    cin >> choise ;

    switch (choise)
    {
    
    case 1 :
    system("cls") ;
    edit_product() ;
    break;

    case 2 :
    system("cls") ;
    admin() ;
    break;

    case 3 :
    system("cls") ;
    main_menu() ;
    break;

    case 4 :
    system("cls") ;
    exit_screen() ;
    exit(0) ;
    break;


    
    default:
    system("cls") ;
    wrong_choise_screen() ;

    int choise ;
    cin >> choise ;

    switch(choise)
    {
    case 1 :
    system("cls") ;
    main_menu() ;
    break;

    case 2 :
    system("cls") ;
    exit_screen() ;
    exit(0) ;
    break;

    default :
    break;

    }
    break;
    }
    
    }
    }
    }
    void delete_product()
    {
    fstream database ;
    database.open("database.txt" , ios::in) ;
    if (!database || database.peek() == -1)
    {
        if (database)
        {
        empty_database_screen() ;
        }
        database.close() ;
        
        cout << "1] main menu  \n" ;
        cout << "2] admin menu \n" ;
        cout << "3] exit       \n" ;

        enum enChoises {enMain=1 , enAdmin , enExit} ;
        int choise ;
        cin >> choise ;

        switch (choise)
        {
        case enMain :
        system("cls") ;
        main_menu() ;
        break;

        case enAdmin :
        system("cls") ;
        admin() ;
        break;

        case enExit :
        system("cls") ;
        exit_screen() ;
        exit(0) ;
        break;

        default:
        system("cls") ;
        break;
        }
    }
    else 
    {
    
    if (!(!database || database.peek() == -1))
    market_data() ;
    cout << "#######################################################\n" ;
    cout << "                                                       \n" ;
    cout << "                  enter product code                   \n" ;
    cout << "                                                       \n" ;
    cout << "#######################################################\n" ;
    
    int search_product_code ;
    cin >> search_product_code ;

    string product_name ;
    int product_code ;
    int product_price ;
    float product_discount ;

    fstream new_data_base ;
    new_data_base.open("new_data_base.txt" , ios::out|ios::app) ;


    bool is_deleted = 0 ;
    while (database >> product_name >> product_code >> product_price >> product_discount)
    {
        if (search_product_code != product_code)
        {
            new_data_base << " " << product_name << " " << product_code << " " << product_price << " " << product_discount << "\n" ;
        }

        else
        is_deleted = 1 ;
    }


    if (!is_deleted)
    {

    system("cls") ;
    cout << "#########################################\n" ;
    cout << "there is no code like this in data base  \n" ;
    cout << "#########################################\n" ;
    cout << "1] delete another product   \n" ;
    cout << "2] back to admin menu       \n" ;
    cout << "3] back to main menu        \n" ;
    cout << "4] exit                     \n" ;

    int choise ;
    cin >> choise ;

    switch (choise)
    {
    
    case 1 :
    system("cls") ;
    delete_product() ;
    break;

    case 2 :
    system("cls") ;
    admin() ;
    break;

    case 3 :
    system("cls") ;
    main_menu() ;
    break;

    case 4 :
    system("cls") ;
    exit_screen() ;
    exit(0) ;
    break;



    default:
    system("cls") ;
    wrong_choise_screen() ;

    int choise ;
    cin >> choise ;

    switch (choise)
    {
    
    case 1 :
    system("cls") ;
    main_menu() ;
    break;

    case 2 :
    system("cls") ;
    exit_screen() ;
    exit(0) ;
    break;

    
    default:
    break;
    }

    break;
    }


    }

    else
    {
    database.close() ;
    new_data_base.close() ;

    remove("database.txt") ;
    rename("new_data_base.txt" , "database.txt") ;

    system("cls") ;
    //market_data() ;
    product_deleted_successfully() ;
    cout << "1] delete another product \n" ;
    cout << "2] back to admin menu     \n" ;
    cout << "3] back to main menu      \n" ;
    cout << "4] exit                   \n" ;

    int choise ;
    cin >> choise ;

    switch (choise)
    {
   
    case 1 :
    system("cls") ;
    delete_product() ;
    break;

    case 2 :
    system("cls") ;
    admin() ;
    break;

    case 3 :
    system("cls") ;
    main_menu() ;
    break;

    case 4 :
    system("cls") ;
    exit_screen() ;
    exit(0) ;
    break;
    
    default:
    system("cls") ;
    break;
    }






    }
    
    }
    }
    void buyer()
    {
    cout << "#######################################################\n" ;
    cout << "                                                       \n" ;
    cout << "               welcome to my market                    \n" ;
    cout << "                                                       \n" ;
    cout << "#######################################################\n" ;
    cout << "1] buy \n" ;
    cout << "2] back to main menue \n" ;
    cout << "3] exit \n" ;


    
    int choise ;
    cin >> choise ;

    switch (choise)
    {
    
    case 1 :
    system("cls") ;
    buy_product() ;
    break;

    case 2 :
    system("cls") ;
    main_menu() ;
    break;

    case 3 :
    system("cls") ;
    exit_screen() ;
    exit(0) ;

    
    default:
    system("cls") ;
    wrong_choise_screen() ;
    int choise ;
    cin >> choise ;

    switch (choise)
    {
    
    case 1 :
    system("cls") ;
    main_menu() ;
    break;

    case 2 :
    system("cls") ;
    exit_screen() ;
    exit(0) ;
    break;

    
    default:
    system("cls") ;
    exit_screen() ;
    exit(0) ;
    break;
    }

    break;
    }
    }
    void buy_product()
    {
    market_data() ;
    string product_name ;
    int product_code ;
    int product_price ;
    float product_discsount ;

    int purchase_code[100] ;
    int purchase_quantity[100] ;

    int index = 0 ;
    int choise ;

    int total = 0 ;

    fstream database ;

    do 
    {
    cout << "enter product code \n" ;
    cin >> purchase_code[index] ;

    cout << "enter quantity     \n" ;
    cin >> purchase_quantity[index] ;

    bool is_duplicated = 0 ;
    for (int i=0 ; i<index ; i++)
    {
        if (purchase_code[i] == purchase_code[index])
        {
            is_duplicated = 1 ;
            break;
        }
    }

    database.open("database.txt" , ios::in) ;
    bool is_exist = 0 ;
    while(database >> product_name >> product_code >> product_price >> product_discsount)
    {
        if(purchase_code[index] == product_code)
        {
        is_exist = 1 ;
        break;
        }
    }
    database.close() ;

    if (is_duplicated || !is_exist)
    {
        if (is_duplicated)
        {
        system("cls") ;
        cout << "duplicated product code !!!    \n" ;
        cout << "1] enter another code          \n" ;
        cout << "2] pay the bill                \n" ;
        cin >> choise ;
        system("cls") ;
        market_data() ;
        }
        else
        {
        system("cls") ;
        cout << "product is out of stock !!!    \n" ;
        cout << "1] enter another code          \n" ;
        cout << "2] pay the bill                \n" ;
        cin >> choise ;
        system("cls") ;
        market_data() ;
        }

    }
    else
    {
    index ++ ;
    
    cout << "1] buy another product \n" ;
    cout << "2] pay the bill        \n" ;

    cin >> choise ;
    }
    }
    while(choise == 1) ;

    if (choise == 2)
    {
        system("cls") ;
        int price_after_discount ;
        cout << "name\t\t" << "code\t" << "quantity\t" << "default price\t" <<"discount\t" << "discounted price \n" ;
        for(int i=0 ; i<index ; i++)
        {
            database.open("database.txt" , ios::in) ;

            while (database >> product_name >> product_code >> product_price >> product_discsount)
            {
                if (purchase_code[i] == product_code)
                {
                    price_after_discount = purchase_quantity[i]*((product_price) - (product_discsount*product_price/100.0));
                    total += price_after_discount ;
                    cout << product_name << "\t\t" << product_code << "\t     "  << purchase_quantity[i] << "\t\t    " << product_price << "\t" << product_discsount << "\t\t\t" << price_after_discount << "\n" ;
                    database.close() ;
                    break;
                }
            }
            
        }
    }

    cout << "___________________________________ \n" ;
    cout << "total price = " << total << "       \n" ;
    cout << "___________________________________ \n" ;
    exit_screen() ;
    }
    void check_admin()
    {
        string email , password ;
        cout << "#######################################################\n" ;
        cout << "                 enter email please                    \n" ;
        cout << "#######################################################\n" ;
        cin >> email ;

        system("cls") ;

        cout << "#######################################################\n" ;
        cout << "                enter password please                  \n" ;
        cout << "#######################################################\n" ;
        cin >> password ;






        string correct_email = "amr" ;
        string correct_password = "0000" ;

        if(email == correct_email && password == correct_password)
        {
        system("cls") ;
        admin() ;
        }

        else
        {
            system("cls") ;
            access_denied_screen() ;
            int choise ;
            cin >> choise ;

            switch (choise)
            {

            case 1 :
            system("cls") ;
            main_menu() ;
            break;

            case 2 :
            system("cls") ;
            exit_screen() ;
            exit(0) ;
            break;
            
            default:
            system("cls") ;
            exit_screen() ;
            exit(0) ;
            break;
            }
        }
    }
    void exit_screen()
    {

    cout << "#######################################################\n" ;
    cout << "                                                       \n" ;
    cout << "          we are pleased to deal with you              \n" ;
    cout << "          Dear : customer / admin                      \n" ;
    cout << "                                                       \n" ;
    cout << "          PROGRAM DESIGNED BY AMR MOHAMED              \n" ;
    cout << "          first step to 100k has been done ^-^         \n" ;
    cout << "                                                       \n" ;
    cout << "#######################################################\n" ;

    }
    void access_denied_screen()
    {

        cout << "#######################################################\n" ;
        cout << "                                                       \n" ;
        cout << "                     access denied                     \n" ;
        cout << "                                                       \n" ;
        cout << "#######################################################\n" ;
        cout << "1] back to main menu \n" ;
        cout << "2] exit  \n" ;
    }  
    void product_added_sucessfully()
    {
    market_data() ;
    cout << "#######################################################\n" ;
    cout << "                                                       \n" ;
    cout << "               product added successfully              \n" ;
    cout << "                                                       \n" ;
    cout << "#######################################################\n" ;

    }
    void product_edited_sucessfully()
    {
    market_data() ;
    cout << "#######################################################\n" ;
    cout << "                                                       \n" ;
    cout << "              product edited successfully              \n" ;
    cout << "                                                       \n" ;
    cout << "#######################################################\n" ;

    }
    void product_deleted_successfully()
    {
    market_data() ;
    cout << "#######################################################\n" ;
    cout << "                                                       \n" ;
    cout << "             product deleted successfully              \n" ;
    cout << "                                                       \n" ;
    cout << "#######################################################\n" ;

    }
    void market_data()
    {
        string product_name ;
        int product_code ;
        int product_price ;
        float product_disscount ;

        fstream database ;
        database.open("database.txt" , ios::in) ;

        if (!database)
        {
         empty_database_screen() ;
        }
        else
        {
            cout << "name \t    " << "code       " << "price \t" << "discount \t\t" << "\n" ;
            cout << "===========================================================================\n" ;
            while (database >> product_name >> product_code >> product_price >> product_disscount)
            { 
                cout << product_name << "   |   " << product_code << "   |   " << product_price << "   |   " << product_disscount << "\t|\n" ;
                cout << "___________________________________________________________________________\n" ;
            }

            database.close() ;
            
        }

    }
    void wrong_choise_screen()
    {
    cout << "#######################################################\n" ;
    cout << "                                                       \n" ;
    cout << "               choose from given choises               \n" ;
    cout << "                                                       \n" ;
    cout << "#######################################################\n" ;
    cout << "1] back to main menue \n" ;
    cout << "2] exit  \n" ;

    }
    void empty_database_screen()
    {
            cout << "#######################################################\n" ;
            cout << "                                                       \n" ;
            cout << "              DATABASE IS EMPTY !!!!!!!!               \n" ;
            cout << "                                                       \n" ;
            cout << "#######################################################\n" ;  
    }
};



int main()
{

    mymarket amr ;
    amr.main_menu();
}
