require "formula"

class Ntd < Formula
  homepage "http://ntd.kasoki.de"
  url "https://github.com/kasoki/ntd/archive/v0.1.1.tar.gz"
  sha1 "d0a73e8835d8164779118e81978fc9a386ad3f71"

  depends_on "premake" => :build

  def install
    system "premake4", "gmake"
    system "make"

    lib.install "libntd.dylib"
    include.install "ntd/include/ntd"
  end

  test do
    (testpath / "test.cpp").write <<-EOS.undent
      #include <ntd/curry.hpp>

      int main() {
        auto add = [](auto x, auto y) {
            return x + y;
        }

        auto add4 = ntd::curry(add, 4);

        add4(10);

        return 0;
      }
    EOS
    system ENV.cc, "test.cpp", "-std=c++1y", "-lntd"
  end
end