

std::string token;
while (true) {
  std::getline(std::cin, token, ' ');
  if (token == "stop") {  // Выход из цикла при условии, что в token было помещено "stop"
    break;
  }
  
  /* Код для обработки выражения */
}
Для преобразования std::string в число можно воспользоваться функцией std::stoll. Пример:

std::string token = "12345";  // Задаем строку со значением "12345"
long long int number = std::stoll(token);  // Преобразовываем строку в число типа long long int