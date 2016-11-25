using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication6
{
    public partial class CreateEVolumeDialog : Form
    {
        
        public CreateEVolumeDialog()
        {
            InitializeComponent();

        }

        public string TotalSize { get { return TotalSizeTextBox.Text; } }
        public string SizeType
        {
            get
            {
                if (MBSizeType.Checked)
                {
                    return "MB";
                }
                else if (GBSizeType.Checked)
                {
                    return "GB";
                }
                else if (TBSizeType.Checked)
                {
                    return "TB";
                }
                else
                {
                    return "";
                }                                                                     
            }
        }

        public string Passphrase { get { return PassphraseTextBox.Text; } }

        public string eVolumeLocation { get { return eVolumeLocationTextBox.Text; } }

        public static eVolumeInfo ShowAndReturneVolumeInfo()
        {
            var dialog = new CreateEVolumeDialog();
            
            if (dialog.ShowDialog() == DialogResult.OK)
            {
                eVolumeInfo info = new eVolumeInfo();
                info.TotalSize = Convert.ToInt32(dialog.TotalSize.Trim());
                info.SizeType = dialog.SizeType;
                info.Passphrase = dialog.Passphrase;
                info.Location = dialog.eVolumeLocation;
                return info;
            }
            else
            {
               return null;
            }
           
        }

       
    }
}
