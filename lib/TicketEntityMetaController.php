<?php

class TicketEntityMetaController extends EntityDefaultMetadataController {
  public function entityPropertyInfo() {
    $info['properties'] = array(
      'uid'     => array('type' => 'user',  'label' => 'Author'),
      //'term'    => array('type' => 'string',  'label' => 'Term'),
      //'review'  => array('type' => 'integer', 'label' => 'Review'),
      //'group'   => array('type' => 'integer', 'label' => 'Group'),
      'created' => array('type' => 'date',    'label' => 'Created'),
      'changed' => array('type' => 'date',    'label' => 'Change'),
    );

    return array($this->type => $info);
  }
}