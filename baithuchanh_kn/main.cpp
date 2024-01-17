#include <iostream>
#include <string>
#include <algorithm>

class Vemaybay {
public:
    // Hàm t?o
    Vemaybay(std::string tenchuyen, std::string ngaybay, double giave)
        : tenchuyen(tenchuyen), ngaybay(ngaybay), giave(giave) {}

    // Hàm h?y
    ~Vemaybay() {}

    // Nh?p thông tin vé máy bay
    void Nhap() {
        std::cout << "Nhap ten chuyen: ";
        std::cin >> tenchuyen;
        std::cout << "Nhap ngay bay: ";
        std::cin >> ngaybay;
        std::cout << "Nhap gia ve: ";
        std::cin >> giave;
    }

    // Xu?t thông tin vé máy bay
    void Xuat() const {
        std::cout << "Ten chuyen: " << tenchuyen << std::endl;
        std::cout << "Ngay bay: " << ngaybay << std::endl;
        std::cout << "Gia ve: " << giave << std::endl;
    }

    // Hàm tr? v? giá vé
    double getGiave() const {
        return giave;
    }

private:
    std::string tenchuyen;
    std::string ngaybay;
    double giave;
};

class Nguoi {
public:
    // Hàm t?o
    Nguoi(std::string hoten, std::string gioitinh, int tuoi)
        : hoten(hoten), gioitinh(gioitinh), tuoi(tuoi) {}

    // Hàm h?y
    ~Nguoi() {}

    // Nh?p thông tin ng??i
    void Nhap() {
        std::cout << "Nhap ho ten: ";
        std::cin >> hoten;
        std::cout << "Nhap gioi tinh: ";
        std::cin >> gioitinh;
        std::cout << "Nhap tuoi: ";
        std::cin >> tuoi;
    }

    // Xu?t thông tin ng??i
    void Xuat() const {
        std::cout << "Ho ten: " << hoten << std::endl;
        std::cout << "Gioi tinh: " << gioitinh << std::endl;
        std::cout << "Tuoi: " << tuoi << std::endl;
    }

protected:
    std::string hoten;
    std::string gioitinh;
    int tuoi;
};

class HanhKhach : public Nguoi {
public:
    // Hàm t?o
    HanhKhach(std::string hoten, std::string gioitinh, int tuoi)
        : Nguoi(hoten, gioitinh, tuoi), ve(nullptr), soluong(0) {}

    // Hàm h?y
    ~HanhKhach() {
        delete[] ve;
    }

    // Nh?p thông tin hành khách
    void Nhap() {
        Nguoi::Nhap();
        std::cout << "Nhap so luong ve: ";
        std::cin >> soluong;

        // C?p phát ??ng m?ng vé máy bay
        ve = new Vemaybay[soluong];
        for (int i = 0; i < soluong; ++i) {
            std::cout << "Nhap thong tin ve may bay thu " << i + 1 << ":" << std::endl;
            ve[i].Nhap();
        }
    }

    // Xu?t thông tin hành khách
    void Xuat() const {
        Nguoi::Xuat();
        std::cout << "So luong ve: " << soluong << std::endl;
        for (int i = 0; i < soluong; ++i) {
            std::cout << "Thong tin ve may bay thu " << i + 1 << ":" << std::endl;
            ve[i].Xuat();
        }
    }

    // Tính t?ng s? ti?n ph?i tr? c?a hành khách
    double TongTien() const {
        double tongTien = 0;
        for (int i = 0; i < soluong; ++i) {
            tongTien += ve[i].getGiave();
        }
        return tongTien;
    }

private:
    Vemaybay* ve;
    int soluong;
};

int main() {
    int n;
    std::cout << "Nhap so luong hanh khach: ";
    std::cin >> n;

    HanhKhach* danhSachHanhKhach = new HanhKhach[n];

    for (int i = 0; i < n; ++i) {
        std::cout << "Nhap thong tin hanh khach thu " << i + 1 << ":" << std::endl;
        danhSachHanhKhach[i].Nhap();
    }

    // S?p x?p danh sách hành khách theo chi?u gi?m d?n c?a t?ng ti?n
    std::sort(danhSachHanhKhach, danhSachHanhKhach + n, [](const HanhKhach& a, const HanhKhach& b) {
        return a.TongTien() > b.TongTien();
        });

    std::cout << "\nDanh sach hanh khach va so tien phai tra tuong ung:" << std::endl;
    for (int i = 0; i < n; ++i) {
        danhSachHanhKhach[i].Xuat();
        std::cout << "Tong tien phai tra: " << danhSachHanhKhach[i].TongTien() << std::endl;
        std::cout << "------------------------------------" << std::endl;
    }

    delete[] danhSachHanhKhach;

    return 0;
}
