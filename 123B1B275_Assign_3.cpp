//Name : SWARNIM SURVASE, PRN:123B1B275 , ASSIGNMENT NO 3
//Consider the playlist in a music player. Implement a playlist feature in music player application using singly linked list. Each song in the playlist is represented as a node in the linked list. 
//Each node contains information about the song (such as title or artist or duration, etc.). The playlist should allow users to: 
//a. Add songs
//b. Remove songs
//c. Display the entire playlist
//d. Play specific songs

#include<iostream>
using namespace std;

class song {
    public:
    string title;     // Song title
    string artist;    // Song artist
    song* next;       // Pointer to the next song

    // Constructor to initialize the next pointer
    song() {
        next = NULL;
    }

    // Function to read song details
    void read() {
        cout << "Enter title : ";
        cin >> title;
        cout << "Enter artist : ";
        cin >> artist;
    }

    // Function to display song details
    void display() {
        cout << "Title is : " << title << endl;
        cout << "Artist is : " << artist << endl;
    }
};

class playlist {
    public:
    song* head;  // Pointer to the first song in the playlist

    // Constructor to initialize the head pointer
    playlist() {
        head = NULL;
    }

    // Function to display the entire playlist
    void displayP() {
        if (head == NULL) {
            cout << "List is empty" << endl;
        } else {
            song* cn = head;  // Current node pointer
            while (cn != NULL) {
                cn->display();
                cn = cn->next;
            }
        }
    }

    // Function to add a song at the end of the playlist
    void addSong() {
        song* nn = new song;  // New song node
        nn->read();

        if (head == nullptr) {
            head = nn;  // Set the new song as the head if the list is empty
        } else {
            song* cn = head;
            while (cn->next != NULL) {  // Traverse to the last song
                cn = cn->next;
            }
            cn->next = nn;  // Add new song at the end
        }
    }

    // Function to insert a song after a specific song
    void insertP() {
        string afteratitle;
        cout << "Enter title after which you want to insert the song: ";
        cin >> afteratitle;

        song* nn = new song;
        nn->read();
        song* cn = head;

        // Traverse to find the song with the given title
        while (cn != NULL && cn->title != afteratitle) {
            cn = cn->next;
        }

        if (cn != NULL) {  // If the song is found
            nn->next = cn->next;
            cn->next = nn;
        } else {
            delete nn;  // If the song isn't found, delete the new node
            cout << "Song with title " << afteratitle << " not found." << endl;
        }
    }

    // Function to insert a song at the start of the playlist
    void start() {
        song* nn = new song;
        nn->read();
        nn->next = head;  // Point new song's next to current head
        head = nn;        // Set the new song as the new head
    }

    // Function to delete a song by title
    void del() {
        string deleteS;
        cout << "Enter title to be deleted: ";
        cin >> deleteS;

        song* cn = head;

        // If the head song is to be deleted
        if (cn != NULL && cn->title == deleteS) {
            head = cn->next;
            delete cn;
            cout << "Song deleted\n";
            return;
        }

        // Traverse to find the song to be deleted
        while (cn->next != nullptr && cn->next->title != deleteS) {
            cn = cn->next;
        }

        // If the song is found
        if (cn->next != nullptr) {
            song* toDelete = cn->next;
            cn->next = toDelete->next;
            delete toDelete;
            cout << "Song deleted." << endl;
        } else {
            cout << "Song with title " << deleteS << " not found." << endl;
        }
    }
};

int main() {

    playlist p;  // Create a playlist object
    int choice;

    // Menu-driven program
    do {
        cout << "1. Add Song\n2. Display Playlist\n3. Insert Song at Position\n4. Insert Song at Start\n5. Delete Song\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Handle user choices
        switch (choice) {
            case 1:
                p.addSong();
                break;
            case 2:
                p.displayP();
                break;
            case 3:
                p.insertP();
                break;
            case 4:
                p.start();
                break;
            case 5:
                p.del();
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }

    } while (choice != 6);  

    return 0;
}
