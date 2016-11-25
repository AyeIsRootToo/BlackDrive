using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Runtime.InteropServices;

namespace WindowsFormsApplication6
{
    public partial class FileBrowser : Form
    {
        [DllImport("CMPS 285.dll", CallingConvention = CallingConvention.Cdecl)] //import the compiled cpp code, must be placed in the same place as the GUI .exe
        static extern void encrypt_h(string iv, string key, string inputFile, string outputFile);
        [DllImport("CMPS 285.dll", CallingConvention = CallingConvention.Cdecl)]
        static extern void decrypt_h(string iv, string key, string inputFile, string outputFile);
        public FileBrowser()
        {
            InitializeComponent();            
        }
        

        private void PopulateTreeView(string path)
        {
            TreeNode rootNode;
            
            DirectoryInfo info = new DirectoryInfo(path);
            //DirectoryInfo info = new DirectoryInfo(@"/");
            //DirectoryInfo info = new DirectoryInfo("C:\\Test");
            //MessageBox.Show(info.ToString());
            if (info.Exists)
            {
                treeView1.Nodes.Clear();
                rootNode = new TreeNode(info.Name);
                rootNode.Tag = info;
                GetDirectories(info.GetDirectories(), rootNode);
                treeView1.Nodes.Add(rootNode);
            }
        }

        private void GetDirectories(DirectoryInfo[] subDirs, TreeNode nodeToAddTo)
        {
            TreeNode aNode;
            DirectoryInfo[] subSubDirs;
            foreach (DirectoryInfo subDir in subDirs)
            {
                aNode = new TreeNode(subDir.Name, 0, 0);
                aNode.Tag = subDir;
                aNode.ImageKey = "folder";
                //aNode.ImageKey = "file";
                subSubDirs = subDir.GetDirectories();
                if (subSubDirs.Length != 0)
                {
                    GetDirectories(subSubDirs, aNode);
                }
                nodeToAddTo.Nodes.Add(aNode);
            }
        }
        void treeView1_NodeMouseClick(object sender, TreeNodeMouseClickEventArgs e)
        {
            TreeNode newSelected = e.Node;
            listView1.Items.Clear();
            DirectoryInfo nodeDirInfo = (DirectoryInfo)newSelected.Tag;
            ListViewItem.ListViewSubItem[] subItems;
            ListViewItem item = null;

            foreach (DirectoryInfo dir in nodeDirInfo.GetDirectories())
            {
                item = new ListViewItem(dir.Name, 0);
                subItems = new ListViewItem.ListViewSubItem[]
                          {new ListViewItem.ListViewSubItem(item, "Directory"),
                   new ListViewItem.ListViewSubItem(item,
                dir.LastAccessTime.ToShortDateString())};
                item.SubItems.AddRange(subItems);
                listView1.Items.Add(item);
            }
            foreach (FileInfo file in nodeDirInfo.GetFiles())
            {
                item = new ListViewItem(file.Name, 1);
                
                subItems = new ListViewItem.ListViewSubItem[]
                          { new ListViewItem.ListViewSubItem(item, "File"),
                   new ListViewItem.ListViewSubItem(item,
                file.LastAccessTime.ToShortDateString())};

                item.SubItems.AddRange(subItems);
                listView1.Items.Add(item);
            }

            listView1.AutoResizeColumns(ColumnHeaderAutoResizeStyle.HeaderSize);
        }
              
        private void selectDirectoryToolStripMenuItem_Click(object sender, EventArgs e)
        {
            string folderPath = "";
            FolderBrowserDialog directchoosedlg = new FolderBrowserDialog();
            if (directchoosedlg.ShowDialog() == DialogResult.OK)
            {
                folderPath = directchoosedlg.SelectedPath;
            }
           
            PopulateTreeView(folderPath);
            this.treeView1.NodeMouseClick += new TreeNodeMouseClickEventHandler(this.treeView1_NodeMouseClick);
        }

        private void createEVolumeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            var eVolumeInfo = CreateEVolumeDialog.ShowAndReturneVolumeInfo();
            if (eVolumeInfo != null)
            {
                //call backend Create eVolume Methods
                Console.WriteLine(String.Format("Total size: {0}-{1} Passphrase: {2} Location: {3} ", eVolumeInfo.TotalSize, eVolumeInfo.SizeType, eVolumeInfo.Passphrase, eVolumeInfo.Location));
                
                // (Note: this is if they give me an object to pass to them)
                //BackendObject backendObject = new BackendObject();
                //backendObject.TotalSize = eVolumeInfo.TotalSize; (for each property)
                //VFS.CreateEVolume(backendObject); 

                //(Note: do this if they want indiv. parameters)
                //VFS.CreateEVolume(eVolumeInfo.TotalSize, eVolumeInfo.SizeType, .... etc.);
              }
            else
            {
                Console.WriteLine("User cancelled.");
            }
        }

        private void contextMenuStrip_Opening(object sender, CancelEventArgs e)
        {
            Point cursorPos = PointToClient(new Point(Cursor.Position.X, Cursor.Position.Y));
            ListViewHitTestInfo info = listView1.HitTest(cursorPos);
            if(listView1.SelectedItems.Count <= 0 || listView1.SelectedItems[0].SubItems[1].Text.ToLower() != "file")
            {
                e.Cancel = true;
            }
            
         
        }

        private void encryptToolStripMenuItem_Click(object sender, EventArgs e)
        {
      
            string path = String.Format("{0}\\{1}", treeView1.SelectedNode.FullPath, listView1.SelectedItems[0].Text);
           //MessageBox.Show(path);
            encrypt_h("0123456789abcdef", "aaaaaaaaaaaaaaaa", path, path + ".enc");
            //Console.WriteLine(String.Format("Encrypting File {0}", path));
        }

        private void decryptToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //string path = String.Format("{0}\\{1}", treeView1.SelectedNode.FullPath, listView1.SelectedItems[0].Text);
            decrypt_h("0123456789abcdef", "aaaaaaaaaaaaaaaa", "input.enc", "reinput.txt");

            // Console.WriteLine(String.Format("Decrypting File {0}", path));
        }

        private void listView1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void FileBrowser_Load(object sender, EventArgs e)
        {

        }
    }
}
