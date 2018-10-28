//gets selection from user and returns a bool value
//quitSignal=true ends the program (hopefully)
bool getSelection()
{
    bool quitSignal = false;
    cin >> tempSelection;
    cin.ignore(100, '\n');
    selection = toupper(tempSelection);
    switch(selection)
    {
        case 'S':
            displayList(carList, size);
            break;
        case 'I':
            addEntry(carList, size);
            break;
        case 'D':
            removeEntry(carList, size);
            break;
        case 'R':
            searchByOrigin(carList, size);
            break;
        case 'N':
            searchByName(carList, size);
            break;
        case 'M':
            searchByMPG(carList, size);
            break;
        case 'Q':
            writeAndQuit(carList, fileName, size, outFile);
            quitSignal = true;
            break;
        default:
        cout << "not an option! Please enter a valid option";

    return quitSignal;
}
