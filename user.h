#ifndef USER_H
#define USER_H

class User
{
    const static int NAME_SIZE = 12;

public:
    static int getTotalInstances();

    User(char first_name[NAME_SIZE], char last_name[NAME_SIZE], int ip_address, id=-1);  // id=-1 is to determine if a valid id needs to be given to the user

private:
    static int totalUsersInstances;

    int ID;
    int ipAddress;
    char firstName[NAME_SIZE];
    char lastName[NAME_SIZE];

    static void setTotalInstances();

};

#endif // USER_H
