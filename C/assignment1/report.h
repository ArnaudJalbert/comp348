int traversal()
{
    char path[] = "test_files/test.txt";
    char word[] = "frost";

    char *pathPtr = path;
    char *wordPtr = word;

    printf("Looking for word: %s\n", word);

    if (readFile(pathPtr, wordPtr) == 1)
    {
        printf("\nProperly read the file.\n");
        return 0;
    }

    return 1;
}