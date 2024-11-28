#include "list.hpp"

#include <iostream>

void List::insertNode(int data) {
    Node* aux = new Node;
    aux->data = data;
    aux->next = nullptr;
    if (head == nullptr) {
        head = aux;
        tail = aux;
    } else {
        tail->next = aux;
        tail = aux;
    }
}

void List::display() {
    Node* aux = head;
    while (aux != nullptr) {
        std::cout << aux->data << " ";
        aux = aux->next;
    }
    std::cout << std::endl;
}

// Método para inverter os nós da lista
void List::inverte() {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;  // Armazena o próximo nó
        current->next = prev;  // Inverte o ponteiro
        prev = current;        // Move prev para o atual
        current = next;        // Move para o próximo nó
    }

    // Ajusta head e tail após a inversão
    tail = head;
    head = prev;
}