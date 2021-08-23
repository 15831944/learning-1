package certification.io.streams;

/** Subclasses ByteArrayOutputStream to give access to the internal raw buffer. */
public class ByteArrayOutputStream2 extends java.io.ByteArrayOutputStream {
    public ByteArrayOutputStream2() { super(); }
    public ByteArrayOutputStream2(int size) { super(size); }

    /** Returns the internal buffer of this ByteArrayOutputStream, without copying. */
    public synchronized byte[] buf() {
        return this.buf;
    }
}