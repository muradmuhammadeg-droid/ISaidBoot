use std::path::Path;

/// Safe standalone utility to check file extensions before deployment operations
pub fn verify_iso_extension(file_path: &str) -> bool {
    let path = Path::new(file_path);
    
    // Extract the file extension and verify it matches 'iso' safely
    match path.extension() {
        Some(ext) => {
            if ext.to_ascii_lowercase() == "iso" {
                println!("[+] File extension check passed: Target is a valid ISO file structure.");
                true
            } else {
                println!("[-] Validation Error: Target file must have a .iso extension structure.");
                false
            }
        }
        None => {
            println!("[-] Validation Error: The provided path has no file extension.");
            false
        }
    }
}

fn main() {
    println!("--- ISaidBoot!! Rust Storage Validation Library ---");
    // Example test trace
    let test_file = "ubuntu_image.iso";
    verify_iso_extension(test_file);
}
