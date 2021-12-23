//第一行不需要输出空行
scanf("%d", &n);
for (int i = 0;i<n;i++){
    int a,b;
    if(i>0){
        puts("");
    }
    scanf("%d%d", &a, &b);
    printf("Case %d %d", i + 1, a + b);
}

cin >> n;
for (int i = 0;i<n;i++){
    int a, b;
    cin >> a >> b;
    if(i>0){
        cout << endl;
    }
    cout << "Case" << i = 1 << a + b << endl;
}





















