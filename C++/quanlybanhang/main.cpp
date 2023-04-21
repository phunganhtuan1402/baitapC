#include <stdio.h>
#include <stdint.h>
#include <string>
#include <vector>

using namespace std;

class MonAn {
public:
    MonAn(int id, string ten, double gia) : id(id), ten(ten), gia(gia) {}

    int getId() { return id; }
    string getTen() { return ten; }
    double getGia() { return gia; }

    void setGia(double gia) { this->gia = gia; }

private:
    int id;
    string ten;
    double gia;
};

class Ban {
public:
    Ban(int soBan) : soBan(soBan), trangThai(false) {}

    int getSoBan() { return soBan; }
    bool getTrangThai() { return trangThai; }
    void setTrangThai(bool trangThai) { this->trangThai = trangThai; }

private:
    int soBan;
    bool trangThai;
};

class QuanLy {
public:
    QuanLy() : id(1) {}

    void setSoLuongBan(int n) {
        for (int i = 1; i <= n; i++) {
            danhSachBan.push_back(Ban(i));
        }
    }

    void themMonAn(string ten, double gia) {
        danhSachMonAn.push_back(MonAn(id++, ten, gia));
    }

    void xoaMonAn(int id) {
        for (size_t i = 0; i < danhSachMonAn.size(); i++) {
            if (danhSachMonAn[i].getId() == id) {
                danhSachMonAn.erase(danhSachMonAn.begin() + i);
                break;
            }
        }
    }

    void suaMonAn(int id, string tenMoi, double giaMoi) {
        for (MonAn& monAn : danhSachMonAn) {
            if (monAn.getId() == id) {
                monAn.setGia(giaMoi);
                return;
            }
                }
                printf("Khong tim thay id\n");
    }

    vector<Ban>&getDanhSachBan() { return danhSachBan; }
    vector<MonAn>&getDanhSachMonAn() { return danhSachMonAn; }
private:
    int id;
    vector<Ban> danhSachBan;
    vector<MonAn> danhSachMonAn;
};

class NhanVien {
public:
    NhanVien(QuanLy* quanLy) : quanLy(quanLy) {}

    void hienThiDanhSachBan() {
        vector<Ban>& danhSachBan = quanLy->getDanhSachBan();
        printf("Ban |");
        int i =1;
        for (const Ban& ban : danhSachBan) {
            printf("%d |", i);
            // Thêm phần hiển thị ở đây
        }printf("Trang thai |");
        for (const Ban& ban : danhSachBan) {
            if(ban.setTrangThai(true)){
                printf("x |");
            }else{
                printf(" |");
            }
        }
    }

    void goiMon(int soBan, int idMonAn, int soLuong) {
        Ban& ban = quanLy->getDanhSachBan()[soBan - 1];
        ban.setTrangThai(true);

        // Them logic xu ly goi mon o day
    }

    void suaMon(int soBan, int idMonAnCu, int idMonAnMoi, int soLuong) {
        // Them logic xu ly sua mon o day
    }

    void themMon(int soBan, int idMonAn, int soLuong) {
        // Them logic xu ly them mon o day
    }

    void thanhToan(int soBan) {
        Ban& ban = quanLy->getDanhSachBan()[soBan - 1];
        ban.setTrangThai(false);

        // Them logic xu ly thanh toan o day
    }

private:
    QuanLy* quanLy;
};

int main(int argc, char const *argv[])
{
   

    return 0;
}
