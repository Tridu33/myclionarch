static const auto io_sync_off = [](){
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();


//https://blog.csdn.net/yuzou____5000/article/details/114273970
