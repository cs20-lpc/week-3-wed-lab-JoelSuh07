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
    
    Node* newNode = new Node(elem, nullptr, nullptr);
    Node* current = head;

    if (current == nullptr){
        head = newNode;
    } else{

    while (current -> next != nullptr){
        current = current -> next;
    }

    current -> next = newNode;
    newNode -> prev = current;
    }
    ++this -> length;
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
    this -> length = 0;
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
    if (position < 0 || position > this -> length) throw out_of_range ("Position out of bounds.");

    if (position == 1){
        Node* head = new Node(elem, head, nullptr);
        ++this -> length;
        return;
    }

    Node* current = head;
    Node* prev = nullptr;

    for (int i = 0; i < position -1; ++i) current = current -> next;

    if (current == nullptr){
            /*
            prev -> next = newNode;
            newNode -> next = current;
            ++ this ->length;
            */
           //can use append for end of the list
           append(elem);

            return;
        }
        else{
        Node* newNode = new Node(elem, current, current -> prev);
        current -> prev -> next = newNode;
        current -> prev = newNode;
        ++this -> length;
        }
    }

template <typename T>
bool LinkedList<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
void LinkedList<T>::remove(int position){
    // TODO added by myself
    if (position <0) throw out_of_range ("Position cannot be negative.");
    
    if (position == 0){
        Node* temp = head;
        head = temp -> next;
        delete temp;
        --this ->length;
        return;
    }else{
            Node* temp = nullptr;
            Node* prev = head;

        for (int i = 0; i < position -1; ++i){
            
            if (prev == nullptr || prev -> next == nullptr){
                throw out_of_range ("Position out of bounds.");
            }
            
            prev = prev -> next;

        }
        if (prev -> next == nullptr){
            throw out_of_range ("Position out of bounds.");
        } else{
            temp = prev -> next;
            prev -> next = temp -> next;
            delete temp;
            --this ->length;                
            return;
                
            }
        }
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
ostream& operator<<(ostream& outStream, const LinkedList<T>& myObj) { //a display function 
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
