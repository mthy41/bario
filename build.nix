{
  pkgs
}: 
pkgs.stdenv.mkDerivation {
    pname = "bario";
    version = "0.0.1";
    src = ./.;

    nativeBuildInputs = [ pkgs.gcc ];
    buildInputs = [ pkgs.raylib ];

    installPhase = ''
    mkdir  -p $out/bin
    cp ./target/bin/bario $out/bin
    '';
}
