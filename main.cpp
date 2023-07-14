// Yêu cầu:
// 1. tạo lớp DATE
// 2. hàm tạo không tham số
// 3. hàm tạo có tham số
// 4. nạp chồng toán tử >>
// 5. nạp chồng toán tử +
// 6. nạp chồng toán tử -
// 7. nạp chồng toán tử <<
// 8. nạp chồng toán tử >
// 9. nạp chồng toán tử <
// 10. nạp chồng toán tử ==
// 11. hàm trả về ngày tiếp theo
// 12. hàm trả về ngày hôm qua
// 13. hàm trả về ngày
// 14. hàm trả về tháng
// 15. hàm trả về năm

#include <iostream>
using namespace std;

// tạo lớp DATE
class DATE{
    private:
        int ngay;
        int thang;
        int nam;

    public:
        // hàm khởi tạo không tham số
        DATE(){
            ngay = 0;
            thang = 0;
            nam = 0;
        }

        // hàm khởi tạo có tham số
        DATE(int data1, int data2, int data3){
            ngay = data1;
            thang = data2;
            nam = data3;
        }

        // nạp chồng toán tử nhập >>
        friend istream &operator>>(istream &dt_cin, DATE &dt);

        // nạp chồng toán tử cộng +
        // để đối tượng có thể cộng với 1 số nguyên
        friend DATE operator+(DATE dt, int n);

        // nạp chồng toán tử trừ -
        // để đối tượng có thể trừ với 1 số nguyên
        friend DATE operator-(DATE dt, int n);

        // nạp chồng toán tử hiển thị <<
        friend ostream &operator<<(ostream &dt_cout, DATE &dt);

        // nạp chồng toán tử >
        friend bool operator>(DATE dt1, DATE dt2);

        // nạp chồng toán tử <
        friend bool operator<(DATE dt1, DATE dt2);

        // nạp chồng toán tử ==
        friend bool operator==(DATE dt1, DATE dt2);

        // hàm trả về ngày tiếp theo (tomorrow)
        DATE ngay_tiep_theo(){
            DATE ketQua;

            // tạo mảng chứa dữ liệu
            // của tổng số ngày trong 1 tháng
            int arr[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

            // nếu năm nhuận
            // thì tháng 2 có 29 ngày
            if (nam % 400 == 0 || (nam % 4 == 0 && nam % 100 != 0))
            {
                arr[1] = 29;
            }
            
            // muốn truy cập được tổng số ngày
            // trong 1 tháng
            // thì chỉ cần gõ arr[thang - 1]
            
            // bây giờ cần ghi dữ liệu vào ngày tiếp theo
            if (ngay == 31 && thang == 12)
            {
                ketQua.ngay = 1;
                ketQua.thang = 1;
                ketQua.nam = nam + 1;
            }
            else if (ngay == arr[thang - 1] && thang != 12)
            {
                ketQua.ngay = 1;
                ketQua.thang = thang + 1;
                ketQua.nam = nam;
            }
            else if (ngay != arr[thang - 1])
            {
                ketQua.ngay = ngay + 1;
                ketQua.thang = thang;
                ketQua.nam = nam;
            }

            return ketQua;
        }

        // hàm tra về ngày hôm qua (yesterday)
        DATE ngay_hom_qua(){
            DATE ketQua;

            // tạo mảng chứa dữ liệu
            // của tổng số ngày trong 1 tháng
            int arr[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

            // nếu năm nhuận
            // thì tháng 2 có 29 ngày
            if (nam % 400 == 0 || (nam % 4 == 0 && nam % 100 != 0))
            {
                arr[1] = 29;
            }
            
            // muốn truy cập được tổng số ngày
            // trong 1 tháng
            // thì chỉ cần gõ arr[thang - 1]
            
            // bây giờ cần ghi dữ liệu vào ngày tiếp theo
            if (ngay == 1 && thang == 1)
            {
                ketQua.ngay = 31;
                ketQua.thang = 12;
                ketQua.nam = nam - 1;
            }
            else if (ngay == 1 && thang != 1)
            {
                ketQua.ngay = arr[thang - 2];
                ketQua.thang = thang - 1;
                ketQua.nam = nam;
            }
            else if (ngay != 1)
            {
                ketQua.ngay = ngay - 1;
                ketQua.thang = thang;
                ketQua.nam = nam;
            }

            return ketQua;
        }

        // hàm trả về ngày
        int get_ngay(){
            return ngay;
        }

        // hàm trả về tháng
        int get_thang(){
            return thang;
        }

        // hàm trả về năm
        int get_nam(){
            return nam;
        }
};

istream &operator>>(istream &dt_cin, DATE &dt){
    cout << "Nhap ngay: ";
    dt_cin >> dt.ngay;

    cout << "Nhap thang: ";
    dt_cin >> dt.thang;

    cout << "Nhap nam: ";
    dt_cin >> dt.nam;

    return dt_cin;
}

DATE operator+(DATE dt, int n){
    DATE ketQua;

    if (n == 0)
    {
        ketQua.ngay = dt.ngay;
        ketQua.thang = dt.thang;
        ketQua.nam = dt.nam;
    }
    else if (n > 0)
    {
        // tạo biến item
        DATE item = dt;

        for (int i = 1; i <= n; i++)
        {
            item = item.ngay_tiep_theo();
            ketQua = item;
        }
    }

    return ketQua;
}

DATE operator-(DATE dt, int n){
    DATE ketQua;

    if (n == 0)
    {
        ketQua.ngay = dt.ngay;
        ketQua.thang = dt.thang;
        ketQua.nam = dt.nam;
    }
    else if (n > 0)
    {
        // tạo biến item
        DATE item = dt;

        for (int i = 1; i <= n; i++)
        {
            item = item.ngay_hom_qua();
            ketQua = item;
        }
    }

    return ketQua;
}

ostream &operator<<(ostream &dt_cout, DATE &dt){
    dt_cout << dt.ngay << "/" << dt.thang << "/" << dt.nam;

    return dt_cout;
}

bool operator>(DATE dt1, DATE dt2){
    bool ketQua = false;

    if (dt1.nam == dt2.nam)
    {
        if (dt1.thang == dt2.thang)
        {
            if (dt1.ngay == dt2.ngay)
            {
                ketQua = false;
            }
            else if (dt1.ngay > dt2.ngay)
            {
                ketQua = true;
            }
            else if (dt1.ngay < dt2.ngay)
            {
                ketQua = false;
            }            
        }
        else if (dt1.thang > dt2.thang)
        {
            ketQua = true;
        }
        else if (dt1.thang < dt2.thang)
        {
            ketQua = false;
        }        
    }
    else if (dt1.nam > dt2.nam)
    {
        ketQua = true;
    }
    else if (dt1.nam < dt2.nam)
    {
        ketQua = false;
    }

    return ketQua;
}

bool operator<(DATE dt1, DATE dt2){
    bool ketQua = false;

    if (dt1.nam == dt2.nam)
    {
        if (dt1.thang == dt2.thang)
        {
            if (dt1.ngay == dt2.ngay)
            {
                ketQua = false;
            }
            else if (dt1.ngay < dt2.ngay)
            {
                ketQua = true;
            }
            else if (dt1.ngay > dt2.ngay)
            {
                ketQua = false;
            }            
        }
        else if (dt1.thang < dt2.thang)
        {
            ketQua = true;
        }
        else if (dt1.thang > dt2.thang)
        {
            ketQua = false;
        }        
    }
    else if (dt1.nam < dt2.nam)
    {
        ketQua = true;
    }
    else if (dt1.nam > dt2.nam)
    {
        ketQua = false;
    }

    return ketQua;
}

bool operator==(DATE dt1, DATE dt2){
    bool ketQua = false;

    if (dt1.nam == dt2.nam)
    {
        if (dt1.thang == dt2.thang)
        {
            if (dt1.ngay == dt2.ngay)
            {
                ketQua = true;
            }
            else if (dt1.ngay < dt2.ngay)
            {
                ketQua = false;
            }
            else if (dt1.ngay > dt2.ngay)
            {
                ketQua = false;
            }            
        }
        else if (dt1.thang < dt2.thang)
        {
            ketQua = false;
        }
        else if (dt1.thang > dt2.thang)
        {
            ketQua = false;
        }
    }
    else if (dt1.nam < dt2.nam)
    {
        ketQua = false;
    }
    else if (dt1.nam > dt2.nam)
    {
        ketQua = false;
    }

    return ketQua;
}

int main(){
    // tạo đối tượng
    DATE dt1 = DATE(1, 1, 2023);
    DATE dt2;

    // nhập dữ liệu
    cin >> dt2;                 // ví dụ bạn nhập 1/1/2000 đi

    // hiển thị
    cout << "\ndt1: ";
    cout << dt1 << "\ndt2: ";
    cout << dt2 << "\n\n";

    cout << "dd/MM/yyyy + 365 days\n";
    cout << dt1 + 365 << "\n";
    cout << dt2 + 365 << "\n\n";

    cout << "dd/MM/yyyy - 365 days\n";
    cout << dt1 - 365 << "\n";
    cout << dt2 - 365 << "\n\n";

    // so sánh
    cout << "toan tu so sanh (>, <, ==):\n";
    cout << dt1 << " > " << dt2 << "\t\t=> ket qua: " << (dt1 > dt2) << "\n";
    cout << dt1 << " < " << dt2 << "\t\t=> ket qua: " << (dt1 < dt2) << "\n";
    cout << dt1 << " == " << dt2 << "\t\t=> ket qua: " << (dt1 == dt2) << "\n\n";

    // in ra ngày tiếp theo của dt2
    cout << "Ngay tiep theo cua " << dt2 << ":\n";
    cout << dt2.ngay_tiep_theo() << "\n\n";

    // in ra ngày hôm qua của dt2
    cout << "Ngay hom qua cua " << dt2 << ":\n";
    cout << dt2.ngay_hom_qua() << "\n\n";

    return 0;
}