public class cat {
    public static void main(String[] args) throws Exception {
        if (args.length > 1) {
            System.err.println("Usage: cat [file]");
            System.exit(1);
        }

        java.io.InputStream in = System.in;
        java.io.FileInputStream fis = null;
        if (args.length == 1) {
            try {
                fis = new java.io.FileInputStream(args[0]);
                in = fis;
            } catch (java.io.FileNotFoundException e) {
                System.err.println(args[0] + ": " + e.getMessage());
                System.exit(1);
            }
        }

        byte[] buf = new byte[8192];
        int n;
        java.io.OutputStream out = System.out;
        while ((n = in.read(buf)) != -1) {
            out.write(buf, 0, n);
        }
        out.flush();

        if (fis != null) fis.close();
    }
}
