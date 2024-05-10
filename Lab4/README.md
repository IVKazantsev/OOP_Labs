Шаблонные интерфейсы.
User хранит имя, логин и пароль, и id(?)
Функционал: регистрация, т.е. создание нового пользователя, и авторизация, а также автоавторизация - вход в аккаунт последнего вошедшего без введения пароля.

IUserManager {
void SignIn(User user);
void SignOut(User user):
bool isAuthorized()
}

IRepository<T> {
vector<T> GetAll();
void Add(T User);
void Remove(T user);
void Update(T user);
}

User {
int id;
string login;
string password;
string name;
}
}
IUserRepository<User> : IRepository<T>
{
User GetById(int id);
User GetByLogin(int login);
}

и реализация IUserManager и IUserRepository с сохранением данных в файл

Приложение должно автоматически авторизовать пользователя, добавлять пользователя, поменять текущего пользователя 
