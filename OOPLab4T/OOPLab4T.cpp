/*#include <iostream>
#include <string>
#include <unordered_map>

class ContactBook {
private:
    std::unordered_map<std::string, std::string> contacts;
    int codeError;

public:
    ContactBook() : codeError(0) {}

    // Додати контакт
    void addContact(const std::string& email, const std::string& phoneNumber) {
        contacts[email] = phoneNumber;
    }

    // Отримати номер телефону за електронну пошту
    std::string& operator[](const std::string& email) {
        if (contacts.find(email) != contacts.end()) {
            codeError = 0; // Знайдено контакт
            return contacts[email];
        }
        else {
            codeError = 1; // Контакт не знайдено
            static std::string empty; // Повертаємо порожній рядок
            return empty;
        }
    }

    // Отримати код помилки
    int getErrorCode() const {
        return codeError;
    }

    // Вивести контакти
    friend std::ostream& operator<<(std::ostream& out, const ContactBook& book) {
        for (const auto& pair : book.contacts) {
            out << "Email: " << pair.first << ", Phone: " << pair.second << std::endl;
        }
        return out;
    }

    // Ввести контакти
    friend std::istream& operator>>(std::istream& in, ContactBook& book) {
        std::string email, phoneNumber;
        std::cout << "Enter email: ";
        in >> email;
        std::cout << "Enter phone number: ";
        in >> phoneNumber;
        book.addContact(email, phoneNumber);
        return in;
    }
};

int main() {
    ContactBook contacts;
    contacts.addContact("john@example.com", "+123456789");
    contacts.addContact("jane@example.com", "+987654321");

    // Виведемо контакти
    std::cout << "Contacts:" << std::endl;
    std::cout << contacts;

    // Перевіримо доступність контакту
    std::cout << "Search for jane@example.com: " << contacts["jane@example.com"] << std::endl;
    std::cout << "Search for non-existent contact: " << contacts["nonexistent@example.com"] << std::endl;

    return 0;
}*/
/*#include <iostream>

class VectorShort {
private:
    short* elements;
    int size;
    bool codeError;

public:
    // Конструктори
    VectorShort() : elements(new short[1]), size(1), codeError(false) {
        elements[0] = 0;
    }

    VectorShort(int newSize) : size(newSize), codeError(false) {
        elements = new short[size];
        for (int i = 0; i < size; ++i)
            elements[i] = 0;
    }

    VectorShort(int newSize, short initValue) : size(newSize), codeError(false) {
        elements = new short[size];
        for (int i = 0; i < size; ++i)
            elements[i] = initValue;
    }

    // Конструктор копіювання
    VectorShort(const VectorShort& other) : size(other.size), codeError(other.codeError) {
        elements = new short[size];
        for (int i = 0; i < size; ++i)
            elements[i] = other.elements[i];
    }

    // Деструктор
    ~VectorShort() {
        delete[] elements;
    }

    // Перевантажені оператори
    VectorShort& operator=(const VectorShort& other) {
        if (this != &other) {
            delete[] elements;
            size = other.size;
            codeError = other.codeError;
            elements = new short[size];
            for (int i = 0; i < size; ++i)
                elements[i] = other.elements[i];
        }
        return *this;
    }

    VectorShort& operator+=(const VectorShort& other) {
        for (int i = 0; i < size; ++i)
            elements[i] += other.elements[i];
        return *this;
    }

    VectorShort& operator-=(const VectorShort& other) {
        for (int i = 0; i < size; ++i)
            elements[i] -= other.elements[i];
        return *this;
    }

    VectorShort& operator*=(short scalar) {
        for (int i = 0; i < size; ++i)
            elements[i] *= scalar;
        return *this;
    }

    VectorShort& operator/=(short scalar) {
        if (scalar != 0) {
            for (int i = 0; i < size; ++i)
                elements[i] /= scalar;
        }
        else {
            codeError = true;
        }
        return *this;
    }

    VectorShort& operator%=(short scalar) {
        if (scalar != 0) {
            for (int i = 0; i < size; ++i)
                elements[i] %= scalar;
        }
        else {
            codeError = true;
        }
        return *this;
    }

    VectorShort& operator|=(const VectorShort& other) {
        for (int i = 0; i < size; ++i)
            elements[i] |= other.elements[i];
        return *this;
    }

    VectorShort& operator^=(const VectorShort& other) {
        for (int i = 0; i < size; ++i)
            elements[i] ^= other.elements[i];
        return *this;
    }

    VectorShort& operator&=(const VectorShort& other) {
        for (int i = 0; i < size; ++i)
            elements[i] &= other.elements[i];
        return *this;
    }

    VectorShort operator-() const {
        VectorShort result(*this);
        for (int i = 0; i < size; ++i)
            result.elements[i] = -result.elements[i];
        return result;
    }

    VectorShort operator~() const {
        VectorShort result(*this);
        for (int i = 0; i < size; ++i)
            result.elements[i] = ~result.elements[i];
        return result;
    }

    VectorShort& operator++() {
        for (int i = 0; i < size; ++i)
            ++elements[i];
        return *this;
    }

    VectorShort operator++(int) {
        VectorShort temp(*this);
        operator++();
        return temp;
    }

    VectorShort& operator--() {
        for (int i = 0; i < size; ++i)
            --elements[i];
        return *this;
    }

    VectorShort operator--(int) {
        VectorShort temp(*this);
        operator--();
        return temp;
    }

    bool operator!() const {
        return size == 0;
    }

    // Додаткові функції
    friend std::ostream& operator<<(std::ostream& out, const VectorShort& vec) {
        out << "[ ";
        for (int i = 0; i < vec.size; ++i) {
            out << vec.elements[i];
            if (i != vec.size - 1)
                out << ", ";
        }
        out << " ]";
        return out;
    }
};

int main() {
    VectorShort vec1(3, 5);
    VectorShort vec2(3, 2);

    std::cout << "vec1: " << vec1 << std::endl;
    std::cout << "vec2: " << vec2 << std::endl;

    vec1 += vec2;
    std::cout << "vec1 += vec2: " << vec1 << std::endl;

    VectorShort vec3 = -vec1;
    std::cout << "-vec1: " << vec3 << std::endl;

    VectorShort vec4 = ~vec2;
    std::cout << "~vec2: " << vec4 << std::endl;

    ++vec2;
    std::cout << "++vec2: " << vec2 << std::endl;

    return 0;
}*/

