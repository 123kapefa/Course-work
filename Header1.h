#pragma once
void inputUsersTXT(const int maxUsers, int& countUsers, int ptrSwitch)
{
    string path = "User.txt";
    fstream fin;
    fin.open(path, fstream::in);

    if (fin.is_open())
    {
        if (ptrSwitch == 1)
        {
            // ��� ��� ��� ������ �� ����� � ��������� ������
        }
        else if (ptrSwitch == 2)
        {
            User* users = new User[maxUsers]; // ������� ������ �������� ������ User

            for (int i = 0; i < maxUsers && !fin.eof(); i++)
            {
                string name, surname, login, key, countCardStr;
                int countCard;

                getline(fin, name);
                getline(fin, surname);
                getline(fin, login);
                getline(fin, key);
                getline(fin, countCardStr);
                countCard = stoi(countCardStr);

                users[i].setName(name); // �����������, ��� � ��� ���� ������ ��� ��������� ������ � ������ User
                users[i].setSurname(surname);
                users[i].setLogin(login);
                users[i].setKey(key);

                for (int j = 0; j < countCard; j++)
                {
                    Card card;
                    card.inputCardTXT(countCard);
                    users[i].addCard(card); // �����������, ��� � ��� ���� ����� ��� ���������� ����� ������������
                }

                countUsers++;
            }

            // ����������� ������
            delete[] users;
        }

        fin.close();
    }
    else
    {
        cout << "�� ������� ������� ����!" << endl;
    }
}