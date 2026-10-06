struct Base { ... }; 

struct D1 : Base { ... };

struct D2 : Base { ... }; 

struct D3 : D1, D2 { ... };

Base const * D1BaseToD2Base( Base const * base )
{
    return static_cast<Base const *>(static_cast<D2 const *>(static_cast<D3 const *>(static_cast<D1 const *>(base))));
}


int main(){
    retrun 0;
}