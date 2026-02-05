template <typename T>
LinkedList<T>::LinkedList()
: head(nullptr) { }

template <typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

template <typename T>
void LinkedList<T>::append(const T& elem) {
    // TODO
    Node* current = head;
    Node* newNode = new Node(elem);

    if (current == nullptr){
        current = newNode;
    }

    while (next != nullptr){
        current = current -> next;
    }
    current -> next = newNode;
    delete newNode;
}

template <typename T>
void LinkedList<T>::clear() {
    // TODO
    Node* current = head;
    while (current != nullptr){
        Node* next = current -> next;
        delete current;
        current = next;
    }
    head = nullptr;
}

template <typename T>
T LinkedList<T>::getElement(int position) const {
    // TODO
    if (head == nullptr){
        throw out_of_range("List is empty.");
    }

    Node* current = head;
    int count = 0;
    
    while (current != nullptr){
        
        if (count == position){
            return current -> value;
        }
        
        current = current -> next;
        ++count;
    }
    throw out_of_range("Position out of bounds.");
}

template <typename T>
int LinkedList<T>::getLength() const {
    return this->length;
}

template <typename T>
void LinkedList<T>::insert(int position, const T& elem){
    //TODO added by myself
    if (position < 0) throw out_of_range ("Position cannot be negative.");

    if (position == 0){
        head = new Node(elem, head);
        return;
    }

    Node* current = head;
    Node* prev = nullptr;
    Node* newNode = new Node(elem);
    int count = 0;

    while(current != nullptr){
        if (count == position){
            prev -> next = newNode;
            newNode -> next = current;
            return;
        }
        prev = current;
        current = current -> next;
        ++count;
    } 

    if (count == position){
        prev -> next = newNode;
        return;
    }

    delete newNode;
    throw out_of_range ("Position out of bounds.");
}

template <typename T>
bool LinkedList<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
void LinkedList<T>::replace(int position, const T& elem) {
    // TODO
    if (position < 0){
        throw out_of_range ("Position cannot be negative value.");
    }
    Node* current = head;
    int count = 0;

    /*
    if (head == nullptr){
        throw out_of_range ("List is empty.");
    }
    */

    while (current != nullptr){
        if (count == position){
            current -> value = elem;
            return;
        }
        ++count;
        current = current -> next;
    }
    throw out_of_range ("Position out of bounds.");
}

template <typename T>
ostream& operator<<(ostream& outStream, const LinkedList<T>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "List is empty, no elements to display.\n";
    }
    else {
        typename LinkedList<T>::Node* curr = myObj.head;
        while (curr != nullptr) {
            outStream << curr->value;
            if (curr->next != nullptr) {
                outStream << " --> ";
            }
            curr = curr->next;
        }
        outStream << endl;
    }

    return outStream;
}
